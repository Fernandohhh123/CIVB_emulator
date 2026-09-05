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

#include "menu.hpp"
#include "../../include/cpu.hpp"
#include "draw.hpp"
#include "gotoxy.hpp"

#include <iostream>
#include <stdio.h>

void next_option(Menu *menu){
    if(menu -> option < menu -> arr_len - 1){
        ++ menu -> cursor.y;
        ++ menu -> option;
    }
}

void prev_option(Menu *menu){
	if(menu -> option > 0){
        -- menu -> option;
    }
}

namespace menu_dip{

    void set(uint8_t *dip){
        clear_screen();

        gotoxy(0, 0);

        std::cout << "Input DIP: ";

        scanf("%hhd", dip);

        *dip = *dip & 31;
    }
}

namespace menu_ina {

    void set(uint8_t *ina){
        clear_screen();

        gotoxy(0, 0);

        std::cout << "Input INA: ";

        scanf("%hhd", ina);

        *ina = *ina & 15;
    }
}
