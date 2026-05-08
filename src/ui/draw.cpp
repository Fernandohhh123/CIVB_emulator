/*
Este archivo contiene las funciones para
imprimir cosas en la salida estandar
*/

#include <stdio.h>
#include <string.h>
#include "draw.hpp"
#include "gotoxy.hpp"

void clear_screen(void){
	printf("\033[2J");
}

void draw_box(Rect *rect){
	//hotizontales
	for(int i = 0; i < rect-> w; i++){
		gotoxy(rect->x + i, rect->y);
		printf("-");

		gotoxy(rect->x + i, rect->y + rect->h - 1);
		printf("-");
	}

	//versicales
	for(int i = 0; i < rect-> h; i++){
		gotoxy(rect-> x, rect-> y + i);
		printf("|");

		//verticales
		gotoxy(rect->x + rect->w - 1, rect-> y + i);
		printf("|");
	}

	//esquinas
	gotoxy(rect->x, rect->y); printf("+");
	gotoxy(rect->x, rect->y + rect->h - 1); printf("+");
	gotoxy(rect->x + rect->w - 1, rect->y); printf("+");
	gotoxy(rect->x + rect->w - 1, rect->y + rect->h - 1); printf("+");
}

void draw_layout(Layout layout){
	draw_box(&layout.main_box);
	draw_box(&layout.menu);
	draw_box(&layout.box_title);
	draw_box(&layout.box_registers_title);
	draw_box(&layout.box_registers);
	draw_box(&layout.box_instructions_title);
	draw_box(&layout.box_value_registers);
	draw_box(&layout.box_instructions);

	draw_registers(&layout.box_registers);
	draw_menu_options(&layout.menu);
}

void draw_titles(Layout *layout){
	draw_title_center(&layout->box_title, "civb emulator");
	draw_title_left(&layout->box_registers_title, "Registers");
	draw_title_left(&layout->box_instructions_title, "Instructions");
}

void draw_title_center(Rect *box_title, char *title){
	int title_len = strlen(title);
	int title_x = box_title->x + (box_title->w - title_len) / 2;
	int title_y = box_title->y + 1;

	gotoxy(title_x, title_y);
	printf("%s", title);
}

void draw_title_left(Rect *box_registers_title, char *title){
	int title_len = strlen(title);
	int title_x = box_registers_title->x + 1;
	int title_y = box_registers_title->y + 1;

	gotoxy(title_x, title_y);
	printf("%s", title);
}

void draw_registers(Rect *box_registers){
	const char *name_registers[] = {"Flags",
									"PC",
									"ROM Buffer",
									"ACC",
									"OUTA",
									"OUTB",
									"INA",
									"RA",
									"RD",
									"DIP Switch"};

	int arr_len = sizeof(name_registers) / sizeof(name_registers[0]);

	for(int i = 0; i < arr_len; i++){
		gotoxy(box_registers -> x + 1, i + box_registers -> y + 1);
		printf("%s", name_registers[i]);
	}
}

void draw_menu_options(Rect *box_menu){
	const char *menu_options[] = {"Step",
								  "Run",
								  "Reset",
								  "Set INA",
								  "Set DIP",
								  "Exit"};
	int arr_len = sizeof(menu_options) / sizeof(menu_options[0]);

	for(int i = 0; i < arr_len; i++){
		gotoxy(box_menu -> x + 4, i + box_menu -> y + 1);
		printf("%s", menu_options[i]);
	}
}

//Funcion para imprimir en la tui los valores
// del cpu
void draw_cpu(CPU *cpu, Rect *box_registers_value){

	gotoxy(box_registers_value->x + 1, box_registers_value->y + 1);
	//printfFlags

	gotoxy(box_registers_value->x + 2, box_registers_value->y + 2);
	printf("%x", cpu->pc);

	gotoxy(box_registers_value->x + 2, box_registers_value->y + 3);
	printf("%x", cpu->rom_buffer);
}
