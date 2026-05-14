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

	int offset = 2;

	gotoxy(box_registers_value->x + 1, box_registers_value->y + 1);
	//printfFlags

	// Dato de 13 bits
	gotoxy(box_registers_value->x + 2, box_registers_value->y + 2);
	printf("%x", cpu->pc);

	gotoxy(box_registers_value->x + 2, box_registers_value->y + 3);
	printf("%x", cpu->rom_buffer);

	gotoxy(box_registers_value->x + 2, box_registers_value->y + 4);
	printf("%x", cpu->acc);

	gotoxy(box_registers_value->x + 2, box_registers_value->y + 5);
	printf("%x", cpu->outa);

	gotoxy(box_registers_value->x + 2, box_registers_value->y + 6);
	printf("%x", cpu->outb);

	gotoxy(box_registers_value->x + 2, box_registers_value->y + 7);
	printf("%x", cpu->ina);

	gotoxy(box_registers_value->x + 2, box_registers_value->y + 8);
	printf("%x", cpu->ra);

	gotoxy(box_registers_value->x + 2, box_registers_value->y + 9);
	printf("%x", cpu->rd);

	gotoxy(box_registers_value->x + 2, box_registers_value->y + 10);
	printf("%x", cpu->acc);

	draw_flags(cpu, box_registers_value);
}

#define NO_FLAG 0
#define Z_FLAG 1
#define C_FLAG 2
#define CZ_FLAG 3

void draw_flags(CPU *cpu, Rect *box_registers_value){

	if(cpu -> flags == NO_FLAG){
		gotoxy(box_registers_value->x + 2, box_registers_value->y + 1);
		printf("..");
	} else if(cpu -> flags == Z_FLAG){
		gotoxy(box_registers_value->x + 2, box_registers_value->y + 1);
		printf(".Z");
	} else if(cpu -> flags == C_FLAG){
		gotoxy(box_registers_value->x + 2, box_registers_value->y + 1);
		printf("C.");
	} else if(cpu -> flags == CZ_FLAG){
		gotoxy(box_registers_value->x + 2, box_registers_value->y + 1);
		printf("CZ");
	} else {
		gotoxy(box_registers_value->x + 2, box_registers_value->y + 1);
		printf("??");
	}
}
