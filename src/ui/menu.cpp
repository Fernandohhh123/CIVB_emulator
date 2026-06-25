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
