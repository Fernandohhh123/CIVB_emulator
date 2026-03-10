#include <iostream>
#include <cstdio>
#include <iomanip>
#include <stdio.h>
#include "../include/cpu.hpp"
#include "../include/rom.hpp"
#include "../include/argument_parser.hpp"
#include "../include/control_unity.hpp"

int main(int argc, char *argv[]){

    CPU cpu;
    ROM rom;
    Arguments arguments;

    get_arguments(&arguments, &argc, argv);

    //std::cout << arguments.program_path << std::endl;
    
    rom.program_instructions = get_program_code(arguments.program_path);

    cpu_reset(&cpu);

    //ciclo fetch
    while (true){
        //pc -> rom
        //rom -> cpu
        //pc++ || jmp

        rom.address = cpu.pc;
        //0x0F operando
        //0xF0 opcode

        cpu.rom_buffer = (rom.program_instructions[rom.address] & 0x0F);
        cpu.opcode = rom.program_instructions[rom.address] >> 4;

        execute_instruction(&cpu);

        /*
        printf("ROM Buffer: %x\n", cpu.rom_buffer);
        printf("acc: %x\n", cpu.acc);
        printf("opcode: %x\n", cpu.opcode);*/
        printf("b: %x ", cpu.outb);
        printf("a: %x\n", cpu.outa);

        //getchar();

        if(rom.address >= rom.program_instructions.size()){
            exit(0);
        }

    }

    return 0;
}
