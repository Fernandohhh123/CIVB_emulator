#pragma once
#include "../include/cpu.hpp"

void execute_instruction(cpu::CPU*);
void fetch_cycle(cpu::CPU *cpu, ROM *rom);
