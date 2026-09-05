/*
civb - TUI based 4 bit cpu emulator

    Copyright (C) 2026 Fernando Hernández Valverde

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

    contact: fernandohdzvalverde@gmail.com
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <stdio.h>
#include <thread>
#include <chrono>

#include "../include/cpu.hpp"
#include "../include/rom.hpp"
#include "../include/argument_parser.hpp"
#include "../include/control_unity.hpp"
#include "../include/io_devices.hpp"
#include "../include/kbhit.hpp"

#include "ui/menu.hpp"
#include "ui/rect.hpp"
#include "ui/draw.hpp"
#include "ui/layout.hpp"
#include "ui/gotoxy.hpp"

//ciclo fetch
//pc -> rom
//rom -> cpu
//pc++ || jmp

//0x0F operando
//0xF0 opcode


void main_loop(cpu::CPU*, ROM*, Layout*);
void process_input(Menu*, char);
void print_help(void);
void print_information(void);


int main(int argc, char *argv[]){

    print_information();

    cpu::CPU cpu;
    ROM rom;
    Arguments arguments;
	Layout layout;
	layout = create_layout(20, 50);

	get_arguments(&arguments, &argc, argv);
	load_program_to_rom(&rom, arguments.program_path);

	layout.program_path = arguments.program_path;

	draw_tui(&layout);

    cpu::reset(&cpu);
	rom.address = cpu.pc;

	// ocultar el cursor de la consola
	printf("\e[?25l");

	// restaurar el cursor
	//printf("\e[?25h");

    main_loop(&cpu, &rom, &layout);

    return 0;
}

// bucle principal que conecta todo
void main_loop(cpu::CPU *cpu, ROM *rom, Layout *layout){

	IO_Devices devices;
	Menu menu;

    devices.dip_pc = 0;

	draw_menu_options(&menu, &layout->menu);
    draw_dip(&devices.dip_pc, &layout -> box_value_registers);

	// esta variable es auxiliar para hacer scroll en las instrucciones
	uint32_t instructions_offset = 0;

    while(1){

		if(menu.draw_all != 0){

			draw_tui(layout);
    		draw_menu_options(&menu, &layout->menu);
            draw_dip(&devices.dip_pc, &layout -> box_value_registers);

			menu.draw_all = 0;
		}


		// Imprimimos los datos del cpu
		draw_cpu(cpu, &layout->box_value_registers);
		draw_instructions_address(rom, layout, instructions_offset) ;
		draw_instructions(rom, layout, instructions_offset);
		draw_instruction_pointer(rom, layout, instructions_offset);
        draw_cursor(&menu, &layout -> menu);

		if(kbhit()){
			process_input(&menu, getchar());
		}

        switch(menu.state){

            case STATE_STEP:
                // Ciclo fetch del cpu
                fetch_cycle(cpu, rom, &devices.dip_pc);

                // Ejecutamos la instruccion
                execute_instruction(cpu);
            break;

            case STATE_RUN:
                // Ciclo fetch del cpu
                fetch_cycle(cpu, rom, &devices.dip_pc);

                // Ejecutamos la instruccion
                execute_instruction(cpu);
            break;

            case STATE_RESET:
                cpu::reset(cpu);
            break;

            case STATE_SET_INA:
                menu_ina::set(&cpu -> ina);
                menu.draw_all = 1;
            break;

			case STATE_SET_DIP:
				menu_dip::set(&devices.dip_pc);
				menu.draw_all = 1;
			break;

            case STATE_EXIT:
                gotoxy(0, 0);
                printf("\e[?25h");
                clear_screen();
                exit(0);
            break;

			case STATE_SCROLL_DOWN:
				++ instructions_offset;
			break;

			case STATE_SCROLL_UP:
				if (instructions_offset > 0){
					-- instructions_offset;
				}
			break;

			default:
			break;
        }

        if(menu.state != STATE_RUN){
            menu.state = 0;
        }

        //delay de 100ms
        std::this_thread::sleep_for(
            std::chrono::milliseconds(10)
        );

    } // while
} // main_loop

void process_input(Menu *menu, char key){
	switch(key){
		case 'j':
			next_option(menu);
		break;

		case 'k':
			prev_option(menu);
		break;

		case 'l':
			menu -> state = menu -> option + 1;
		break;

		case 's':
			menu -> state = STATE_STEP;
		break;

		case 'r':
			menu -> state = STATE_RESET;
		break;

		case 'q':
			printf("\e[?25h");
			exit(0);
		break;

		case 'h':
			print_help();
			menu -> draw_all = 1;
		break;

		case 'n':
			menu -> state = STATE_SCROLL_UP; 
		break;

		case 'm':
			menu -> state = STATE_SCROLL_DOWN; 
		break;

		default:
		break;
	}
}

void print_help(void){
	clear_screen();

	gotoxy(0, 0);

	printf("# Ayuda #");

	printf("\n");

	printf("Moverse por el menu\n");
	printf("<K> - Arriba\n");
	printf(" <L> - Seleccionar\n");
	printf("<J> - Abajo\n");

	printf("\n");

    printf("Atajos\n");
    printf("<S> Step\n");
    printf("<R> Reset\n");
    printf("<N> Scroll up\n"); 
    printf("<M> Scroll down\n");
	printf("<Q> Salir\n");

    printf("\n");

	printf("Pulse <Enter> para continuar...");
	getchar();
}

void print_information(void){
  printf("civb emulator  Copyright (C) 2026  Fernando Hernández Valverde \n\
    This program comes with ABSOLUTELY NO WARRANTY.\n\
    This is free software, and you are welcome to redistribute it\n\
    under certain conditions.\n\n");
}

