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

#include "../include/control_unity.hpp"
#include "../include/opcode.hpp"
#include "../include/cpu.hpp"
#include "../include/rom.hpp"
#include <iostream>

void execute_instruction(cpu::CPU *cpu){

    switch(cpu->opcode){
        case static_cast<uint8_t>(Instruction::NOT):
        break;
        case static_cast<uint8_t>(Instruction::NAND):
            cpu->acc = cpu::nand(&cpu->acc, &cpu->rom_buffer, &cpu->flags);
        break;
        case static_cast<uint8_t>(Instruction::ADD):
            cpu->acc = cpu::add(&cpu->acc, &cpu->rom_buffer, &cpu->flags);
        break;
        case static_cast<uint8_t>(Instruction::LDA):
            cpu->acc = cpu->rom_buffer;
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
            cpu->jmp = 1;
            cpu->pc = (cpu->rom_buffer << 4);
            cpu->pc = (cpu->rd | cpu->pc);
        break;
        case static_cast<uint8_t>(Instruction::JPC):
            if(cpu->flags == 2){
				cpu -> jmp = 1;
                cpu->pc = (cpu->rom_buffer << 4);
                cpu->pc = (cpu->rd | cpu->pc);
            }
        break;
        case static_cast<uint8_t>(Instruction::JPZ):
            if(cpu->flags == 4){
                cpu -> jmp = 1;
                cpu->pc = (cpu->rom_buffer << 4);
                cpu->pc = (cpu->rd | cpu->pc);
            }
        break;
    }
    if(cpu->jmp == 0){
        ++ cpu->pc;
    }
    cpu -> jmp = 0;
}

void fetch_cycle(cpu::CPU *cpu, ROM *rom, uint8_t *dip){
        rom->address = cpu->pc;

        rom -> address = rom -> address | (*dip << 8);

        cpu->rom_buffer = (rom->program_instructions[rom->address] & 0x0F);
        cpu->opcode = rom->program_instructions[rom->address] >> 4;
}

