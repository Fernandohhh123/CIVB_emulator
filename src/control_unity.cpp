#include "../include/control_unity.hpp"
#include "../include/opcode.hpp"
#include "../include/cpu.hpp"
#include "../include/rom.hpp"
#include <iostream>

void execute_instruction(CPU *cpu){

    switch(cpu->opcode){
        case static_cast<uint8_t>(Instruction::NOT):
        break;
        case static_cast<uint8_t>(Instruction::NAND):
            cpu->acc = nand(&cpu->acc, &cpu->rom_buffer, &cpu->flags);
        break;
        case static_cast<uint8_t>(Instruction::ADD):
            cpu->acc = add(&cpu->acc, &cpu->rom_buffer, &cpu->flags);
        break;
        case static_cast<uint8_t>(Instruction::LDA):
            cpu->acc = cpu->opcode;
        break;
        case static_cast<uint8_t>(Instruction::OUTA):
            cpu->outa = cpu->acc;
        break;
        case static_cast<uint8_t>(Instruction::OUTB):
            cpu->outb = cpu->acc;
        break;
        case static_cast<uint8_t>(Instruction::INA):
            cpu->acc = cpu->ina;
        break;
        case static_cast<uint8_t>(Instruction::RD):
            cpu->rd = cpu->acc;
        break;
        case static_cast<uint8_t>(Instruction::RA):
            cpu->ra = cpu->acc;
        break;
        case static_cast<uint8_t>(Instruction::LDRA):
            cpu->acc = cpu->ra;
        break;
        case static_cast<uint8_t>(Instruction::JPI):
            if(cpu->jmp == 1){
                cpu->pc = cpu->rom_buffer;
                cpu->pc = (cpu->rd & cpu->pc);
            }
        break;
        case static_cast<uint8_t>(Instruction::JPC):
            if(cpu->jmp == 2){
                cpu->pc = cpu->rom_buffer;
                cpu->pc = (cpu->rd & cpu->pc);
            }
        break;
        case static_cast<uint8_t>(Instruction::JPZ):
            if(cpu->jmp == 4){
                cpu->pc = cpu->rom_buffer;
                cpu->pc = (cpu->rd & cpu->pc);
            }
        break;
    }
    if(cpu->jmp == 0){
        ++cpu->pc;
    }
}

void fetch_cycle(CPU *cpu, ROM *rom){
        rom->address = cpu->pc;
        cpu->rom_buffer = (rom->program_instructions[rom->address] & 0x0F);
        cpu->opcode = rom->program_instructions[rom->address] >> 4;
}