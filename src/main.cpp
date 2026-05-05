
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

int main(int argc, char *argv[]){

    CPU cpu;
    ROM rom;
    Arguments arguments;
	Layout layout;

	layout = create_layout(25, 65);

	clear_screen();
	draw_layout(layout);
	draw_title(&layout.box_title);

	getchar();
    //get_arguments(&arguments, &argc, argv);

    cpu_reset(&cpu);
    rom.program_instructions = get_program_code(arguments.program_path);
    main_loop(&cpu, &rom, &arguments);

    return 0;
}
