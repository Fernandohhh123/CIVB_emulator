#include "menu.hpp"

void next_option(Menu *menu){
	menu -> cursor.y += 1;
}

void prev_option(Menu *menu){
	menu -> cursor.y -= 1;
}
