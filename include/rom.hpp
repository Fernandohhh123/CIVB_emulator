#pragma once
#include <vector>
#include <cstdint>
#include "../include/argument_parser.hpp"

// con 13 bits podemos direccionar de 0x0000 a 0x1FFF
#define ROM_SIZE 8192

typedef struct ROM{
	size_t rom_size = ROM_SIZE;
	// Reservamos los 8kb que puede direccionar el PC
    uint8_t program_instructions [ROM_SIZE] = {0};
    uint16_t address;
    uint8_t output;
}ROM;

void load_program_to_rom(ROM*, char*);
