#include <iostream>
#include <cstdio>
#include <iomanip>
#include <stdio.h>
#include "../include/cpu.hpp"
#include "../include/rom.hpp"
#include "../include/argument_parser.hpp"
#include "../include/control_unity.hpp"
#include "ui/rect.hpp"
#include "ui/draw.hpp"
#include "ui/layout.hpp"

//ciclo fetch
//pc -> rom
//rom -> cpu
//pc++ || jmp

//0x0F operando
//0xF0 opcode


void main_loop(CPU*, ROM*, Arguments*, Layout*);

int main(int argc, char *argv[]){

    CPU cpu;
    ROM rom;
    Arguments arguments;
	Layout layout;
	layout = create_layout(20, 60);

	get_arguments(&arguments, &argc, argv);

	clear_screen();
	draw_layout(layout);
	draw_titles(&layout);

    cpu_reset(&cpu);
//    rom.program_instructions = get_program_code(arguments.program_path);
    main_loop(&cpu, &rom, &arguments, &layout);

    return 0;
}

//buclke principal que conecta todo
void main_loop(CPU *cpu, ROM *rom, Arguments *arguments, Layout *layout){

    while(1){

		//la salida la tengo pensada asi:
		//output(cpu)
		draw_cpu(cpu, &layout->box_value_registers);

		getchar();

		//bucle principal del cpu
        fetch_cycle(cpu, rom);
        execute_instruction(cpu);
        if(rom->address >= rom->program_instructions.size()){
            exit(0);
        }

    }
}
