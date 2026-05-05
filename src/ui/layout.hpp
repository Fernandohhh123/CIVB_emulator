/*
Este archivo contiene funciones para
encapsular la esructura de la tui
*/
#pragma once
#include "rect.hpp"

struct Layout{
	Rect main_box;
	Rect menu;

	Rect box_title;

	Rect box_registers;
	Rect box_registers_title;
	Rect box_value_registers;

	Rect box_instructions;
	Rect box_instructions_title;
};

//esta funcion crea la main_box
Layout create_layout(int, int);
