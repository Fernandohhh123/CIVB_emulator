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

#include "../include/cpu.hpp"
#include <stdio.h>
#include <cstdlib>
#include "../include/control_unity.hpp"

namespace cpu {

    constexpr uint8_t FLAG_ZERO = (1 << 0);
    constexpr uint8_t FLAG_CARRY = (1 << 1);

    uint8_t add(uint8_t* a, uint8_t* b, uint8_t *flags){
        uint8_t resultado = 0;
        resultado = *a + *b;

        //acualizamos las flags
        if((resultado >> 4) > 0){
            resultado = (resultado & 0x0F);

            // 2 = 00000010
            *flags = *flags | 2;
        } else {
            *flags = *flags & 1;
        }

        return resultado;
    }

    uint8_t nand(uint8_t*a, uint8_t*b, uint8_t*flags){
        uint8_t resultado = 0;

        resultado = *a && *b; //nand

        //acualizamos las flags
        if(resultado == 0){
            *flags = *flags | 1;
        } else {
            *flags = *flags & 2;
        }

        return resultado;
    }


    void reset(CPU *cpu){
        cpu->pc = 0;
        cpu->outa = 0;
        cpu->outb = 0;
        cpu->jmp = 0;
        cpu->opcode = 0;
        cpu->flags = 0;
    	cpu->rom_buffer = 0;
    	cpu->acc = 0;
    }

    void show_flags(uint8_t *flags){
        if(*flags == 0){
            printf("00");
        }
        else if(*flags == 1){
            printf("0Z");
        }
        else if(*flags == 2){
            printf("C0");
        }
        else if(*flags == 3){
            printf("CZ");
        }
    }
}
