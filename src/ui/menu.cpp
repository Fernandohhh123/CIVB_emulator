#include "menu.hpp"

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
