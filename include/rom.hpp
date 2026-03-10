#pragma once
#include <vector>
#include <cstdint>
#include "../include/argument_parser.hpp"

typedef struct{
    std::vector<uint8_t> program_instructions;
    uint16_t address;
    uint8_t output;
}ROM;

std::vector<uint8_t> get_program_code(char*);
