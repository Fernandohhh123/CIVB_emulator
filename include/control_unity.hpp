#pragma once
#include "../include/cpu.hpp"

void execute_instruction(CPU*);
void fetch_cycle(CPU *cpu, ROM *rom);