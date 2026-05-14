#pragma once
#include <vector>
#include <cstdint>
#include "../include/argument_parser.hpp"

typedef struct{
	size_t rom_size = 8191;
	// Reservamos los 8kb que puede direccionar el PC
    uint8_t program_instructions [rom_size] = {0};
    uint16_t address;
    uint8_t output;
}ROM;

void load_program_to_rom(ROM*, char*);
