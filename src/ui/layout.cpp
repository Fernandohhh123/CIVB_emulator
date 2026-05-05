#include "layout.hpp"

Layout create_layout(int h, int w){
	Layout layout;

	int start_layout_x = 0;
	int start_layout_y = 0;

	//comienzo en x, comienzo en y, altura, anchura

	layout.main_box = {start_layout_x, start_layout_y, h, w};
	layout.menu = {layout.main_box.w, start_layout_y, h, 20};

	layout.box_title = {start_layout_x, start_layout_y, 3, w};

	layout.box_registers_title = {start_layout_x,
								  layout.box_title.h - 1,
								  3,
								  23};

	layout.box_registers = {start_layout_x,
							layout.box_title.h + layout.box_registers_title.h - 2,
							h - layout.box_registers_title.h - layout.box_registers_title.h + 2,
							18};

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
