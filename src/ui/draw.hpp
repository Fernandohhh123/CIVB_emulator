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
Este archivo contiene las funciones para
imprimir cosas en la salida estandar
*/

#pragma once
#include "../../include/cpu.hpp"
#include "../../include/rom.hpp"
#include "../../include/io_devices.hpp"
#include "rect.hpp"
#include "layout.hpp"
#include "menu.hpp"


void clear_screen(void);
void draw_box(Rect *rect);
void draw_layout(Layout*);

void draw_titles(Layout*);
void draw_title_center(Rect*, char*);
void draw_title_left(Rect*, char*);
void draw_registers(Rect*);
void draw_menu_options(Menu*, Rect*);
void draw_cpu(cpu::CPU*, Rect*);
void draw_flags(cpu::CPU*, Rect*);
void draw_instructions_address(ROM*, Layout*, uint32_t scroll_offset);
void draw_instructions(ROM*, Layout*, uint32_t scroll_offset);
void draw_io_devices_values(IO_Devices*);
void draw_instruction_pointer(ROM*, Layout*, uint32_t);
void draw_cursor(Menu*, Rect*);
void draw_program_path(Layout*);
void draw_help_suggest(Layout*);
void draw_tui(Layout*);
void draw_dip(uint8_t*, Rect*);
