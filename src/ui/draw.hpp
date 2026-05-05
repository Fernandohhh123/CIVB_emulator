/*
Este archivo contiene las funciones para
imprimir cosas en la salida estandar
*/

#pragma once
#include "rect.hpp"
#include "layout.hpp"

void clear_screen(void);
void draw_box(Rect *rect);
void draw_layout(Layout);
void draw_title(Rect*);
