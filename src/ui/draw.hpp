/*
Este archivo contiene las funciones para
imprimir cosas en la salida estandar
*/

#pragma once
#include "../../include/cpu.hpp"
#include "rect.hpp"
#include "layout.hpp"


void clear_screen(void);
void draw_box(Rect *rect);
void draw_layout(Layout);

void draw_titles(Layout*);
void draw_title_center(Rect*, char*);
void draw_title_left(Rect*, char*);
void draw_registers(Rect*);
void draw_menu_options(Rect*);

void draw_cpu(CPU*, Rect*);

void draw_flags(CPU*, Rect*);
