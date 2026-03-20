#include <iostream>
#include <cstdio>
#include <iomanip>
#include <stdio.h>
#include "../include/cpu.hpp"
#include "../include/rom.hpp"
#include "../include/argument_parser.hpp"
#include "../include/control_unity.hpp"


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

    get_arguments(&arguments, &argc, argv);

    //std::cout << arguments.program_path << std::endl;
    
    cpu_reset(&cpu);
    rom.program_instructions = get_program_code(arguments.program_path);
    main_loop(&cpu, &rom);

    return 0;
}
