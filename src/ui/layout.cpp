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

#include "layout.hpp"

Layout create_layout(int h, int w){
	Layout layout;

	int start_layout_x = 0;
	int start_layout_y = 0;

	//comienzo en x, comienzo en y, altura, anchura

	layout.main_box = {start_layout_x, start_layout_y, h, w};
	layout.menu = {layout.main_box.w, start_layout_y, h, 16};

	layout.box_title = {start_layout_x, start_layout_y, 3, w};

	layout.box_registers_title = {start_layout_x,
								  layout.box_title.h - 1,
								  3,
								  24};

	layout.box_registers = {start_layout_x,
							layout.box_title.h + layout.box_registers_title.h - 2,
							h - layout.box_registers_title.h - layout.box_registers_title.h + 2,
							15};

	layout.box_instructions_title = {layout.box_registers_title.w - 1,
									 layout.box_registers_title.h - 1,
									 3,
									 w - layout.box_registers_title.w + 1};

	layout.box_value_registers = {layout.box_registers.w - 1,
								  layout.box_title.h + layout.box_registers_title.h - 2,
								  h - layout.box_registers_title.h - layout.box_registers_title.h + 2,
								  layout.box_registers_title.w - layout.box_registers.w + 1};

	layout.box_instructions = {layout.box_instructions_title.x,
							   layout.box_instructions_title.y + layout.box_instructions_title.h - 1,
							   h - layout.box_registers_title.h - layout.box_registers_title.h + 2,
							   layout.box_instructions_title.w};


	return layout;
}
