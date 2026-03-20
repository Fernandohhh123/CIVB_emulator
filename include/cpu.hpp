#pragma once
#include <stdint.h>
#include "rom.hpp"

typedef struct{
    uint16_t pc;
    uint8_t rom_buffer; //vamos a usar solamente 4 bits
    uint8_t acc;
    uint8_t outa;
    uint8_t outb;
    uint8_t ina;
    uint8_t ra;
    uint8_t rd;
    uint8_t opcode;

    //bit 1 jpi, bit 2, jpc, bit 3, jpz
    uint8_t jmp; //00000000b

    uint8_t flags; //solo usaremos 2 bits
    // 0000000z
    // 000000c0
}CPU;

uint8_t add(uint8_t*, uint8_t*, uint8_t*);
uint8_t nand(uint8_t*, uint8_t*, uint8_t*);

void cpu_reset(CPU*cpu);
void main_loop(CPU*,ROM*);
void fetch_cycle(CPU *cpu);