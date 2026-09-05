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
#include <vector>
#include <cstdint>
#include "../include/argument_parser.hpp"

// con 13 bits podemos direccionar de 0x0000 a 0x1FFF
#define ROM_SIZE 8192

typedef struct ROM{
    size_t rom_size = ROM_SIZE;
    // Reservamos los 8kb que puede direccionar el PC
    uint8_t program_instructions [8192] = {0};
    uint16_t address;
    uint8_t output;
}ROM;

void load_program_to_rom(ROM*, char*);
