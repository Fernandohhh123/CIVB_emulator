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

#pragma once
#include <stdint.h>
#include "rom.hpp"
#include "argument_parser.hpp"

namespace cpu {
    typedef struct{
        uint8_t pc;
        uint8_t rom_buffer; //vamos a usar solamente 4 bits
        uint8_t acc;
        uint8_t outa;
        uint8_t outb;
        uint8_t ina;
        uint8_t ra;
        uint8_t rd;
        uint8_t opcode;

        //bit 1 jpi, bit 2, jpc, bit 3, jpz
        uint8_t jmp; //00000000b

        uint8_t flags; //solo usaremos 2 bits
        // 0000000z
        // 000000c0
    }CPU;

    uint8_t add(uint8_t*, uint8_t*, uint8_t*);
    uint8_t nand(uint8_t*, uint8_t*, uint8_t*);

    void reset(CPU*cpu);
    void fetch_cycle(CPU *cpu);
    void show_flags(uint8_t*);
}
