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

struct Menu{
	Menu_Cursor cursor;
	uint8_t option = 0;
	uint8_t state = 0;
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
