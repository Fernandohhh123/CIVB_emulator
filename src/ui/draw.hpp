/*
Este archivo contiene las funciones para
imprimir cosas en la salida estandar
*/

#pragma once
#include "../../include/cpu.hpp"
#include "../../include/rom.hpp"
#include "../../include/io_devices.hpp"
#include "rect.hpp"
#include "layout.hpp"
#include "menu.hpp"


void clear_screen(void);
void draw_box(Rect *rect);
void draw_layout(Layout);

void draw_titles(Layout*);
void draw_title_center(Rect*, char*);
void draw_title_left(Rect*, char*);
void draw_registers(Rect*);
void draw_menu_options(Menu*, Rect*);
void draw_cpu(cpu::CPU*, Rect*);
void draw_flags(cpu::CPU*, Rect*);
void draw_instructions_address(ROM*, Layout*);
void draw_instructions(ROM*, Layout*);
void draw_io_devices_values(IO_Devices*);
void draw_instruction_pointer(ROM*, Layout*);
void draw_cursor(Menu*, Rect*);
