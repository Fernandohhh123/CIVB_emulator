/*
Este archivo contiene los perifericos de enrada y salida
 #De momento solo hay perifericos de entrada#
- Un dip switch de 5 bits para la parte alta de PC
- Un dip switch que se conecta con el registro ina del cpu
*/

#pragma once
#include <cstdint>

struct IO_Devices{
	// solo ocuparemos 5 bits
	uint8_t dip_pc = 0;

	// solo ocuparemos 4 bits
	uint8_t dip_ina = 0;
};
