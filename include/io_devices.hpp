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

/*
Este archivo contiene los perifericos de enrada y salida
 #De momento solo hay perifericos de entrada#
- Un dip switch de 5 bits para la parte alta de PC
- Un dip switch que se conecta con el registro ina del cpu
*/

#pragma once
#include <cstdint>

struct IO_Devices{
	// solo ocuparemos 5 bits
	uint8_t dip_pc = 0;

	// solo ocuparemos 4 bits
	uint8_t dip_ina = 0;
};
