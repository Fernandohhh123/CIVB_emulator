/*
Este archivo contiene los perifericos de enrada y salida
- Un dip switch de 5 bits para la parte alta de PC
- Un dip switch que se conecta con el registro ina del cpu
*/

#pragma once
#include <cstdint>
#include "../include/cpu.hpp"

struct IO_Devices{
	// solo ocuparemos 5 bits
	uint8_t dip_pc;

	// solo ocuparemos 4 bits
	uint8_t dip_ina;
};

// Esta funcion pone los valores de los perifericos
// de entrada en los registros
void wire_io_to_cpu(IO_Devices*, CPU*);
