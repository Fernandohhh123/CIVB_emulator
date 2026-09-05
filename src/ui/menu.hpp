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
#include <vector>
#include <string_view>

struct Menu_Cursor{
	int x;
	int y;
};

#define STATE_STEP 1
#define STATE_RUN 2
#define STATE_RESET 3
#define STATE_SET_INA 4
#define STATE_SET_DIP 5
#define STATE_EXIT 6
#define STATE_SCROLL_DOWN 7
#define STATE_SCROLL_UP 8

struct Menu{
	Menu_Cursor cursor;
	uint8_t option = 0;
	uint8_t state = 0;

	uint8_t draw_all = 0;

	std::vector <std::string_view> menu_options = {"Step",
												   "Run",
												   "Reset",
												   "Set INA",
												   "Set DIP",
												   "Exit"};
	uint64_t arr_len = menu_options.size();
};

void next_option(Menu*);
void prev_option(Menu*);

namespace menu_dip {
	void set(uint8_t*);
}

namespace menu_ina {
    void set(uint8_t*);
}
