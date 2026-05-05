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
}

void draw_title(Rect *box_title){
	char *title = "civb emulator";
	int title_len = strlen(title);
	int title_x = box_title->x + (box_title->w - title_len) / 2;
	int title_y = box_title->y + 1;

	gotoxy(title_x, title_y);
	printf("%s", title);
}
