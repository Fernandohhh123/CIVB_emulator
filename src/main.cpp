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

int main(int argc, char *argv[]){

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

	draw_menu_options(&menu, &layout->menu);

    while(1){

		if(menu.draw_all != 0){

			draw_tui(layout);
    		draw_menu_options(&menu, &layout->menu);

			menu.draw_all = 0;
		}

		// Imprimimos los datos del cpu
		draw_cpu(cpu, &layout->box_value_registers);
		draw_instructions_address(rom, layout);
		draw_instructions(rom, layout);
		draw_instruction_pointer(rom, layout);
        draw_cursor(&menu, &layout -> menu);

		if(kbhit()){
			process_input(&menu, getchar());
		}

        switch(menu.state){

            case STATE_STEP:
                // Ciclo fetch del cpu
                fetch_cycle(cpu, rom);

                // Ejecutamos la instruccion
                execute_instruction(cpu);
            break;

            case STATE_RUN:
                // Ciclo fetch del cpu
                fetch_cycle(cpu, rom);

                // Ejecutamos la instruccion
                execute_instruction(cpu);
            break;

            case STATE_RESET:
                cpu::reset(cpu);
            break;

            case STATE_EXIT:
                gotoxy(0, 0);
                printf("\e[?25h");
                clear_screen();
                exit(0);
            break;
        }

        if(menu.state == STATE_STEP){
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
	printf("K - Arriba\n");
	printf(" L - Seleccionar\n");
	printf("J - Abajo\n");
	
	printf("\n");

	printf("Pulse <Enter> para continuar...");
	getchar();
}

