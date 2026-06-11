#include <iostream>
#include <cstdio>
#include <iomanip>
#include <stdio.h>
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

//ciclo fetch
//pc -> rom
//rom -> cpu
//pc++ || jmp

//0x0F operando
//0xF0 opcode


void main_loop(cpu::CPU*, ROM*, Layout*);
void process_input(Menu*, char);

int main(int argc, char *argv[]){

    cpu::CPU cpu;
    ROM rom;
    Arguments arguments;
	Layout layout;
	layout = create_layout(20, 50);

	get_arguments(&arguments, &argc, argv);
	load_program_to_rom(&rom, arguments.program_path);

	clear_screen();
	draw_layout(layout);
	draw_titles(&layout);

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

    char key = 0;

    while(1){

		// Imprimimos los datos del cpu
		draw_cpu(cpu, &layout->box_value_registers);
		draw_instructions_address(rom, layout);
		draw_instructions(rom, layout);
		draw_instruction_pointer(rom, layout);

		if(kbhit()){
			process_input(&menu, getchar());
		}

        // Ciclo fetch del cpu
        fetch_cycle(cpu, rom);

        // Ejecutamos la instruccion
        execute_instruction(cpu);

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
			// procesamos la opcion
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

		default:
		break;
	}
}
