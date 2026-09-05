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
Este archivo contiene funciones para
encapsular la esructura de la tui
*/
#pragma once
#include "rect.hpp"

struct Layout{
	Rect main_box;
	Rect menu;

	Rect box_title;

	Rect box_registers;
	Rect box_registers_title;
	Rect box_value_registers;

	Rect box_instructions;
	Rect box_instructions_title;

	char *program_path;
};

//esta funcion crea la main_box
Layout create_layout(int, int);
