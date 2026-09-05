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
#include <cstdint>


enum class Instruction : uint8_t{
    NOT = 0x00,
    NAND = 0x1,
    ADD = 0x2,
    LDA = 0x03,
    OUTA = 0x4,
    OUTB = 0x5,
    INA = 0x6,
    RD = 0x7,
    RA = 0x8,
    LDRA = 0x9,
    JPI = 0xC,
    JPC = 0xD,
    JPZ = 0xE
};
