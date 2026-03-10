#include "../include/cpu.hpp"
#include <stdio.h>


constexpr uint8_t FLAG_ZERO = (1 << 0);
constexpr uint8_t FLAG_CARRY = (1 << 1);

uint8_t add(uint8_t* a, uint8_t* b, uint8_t *flags){
    uint8_t resultado = 0;
    resultado = *a + *b;

    //acualizamos las flags
    if((resultado >> 4) > 0){
        // 2 = 00000010
        *flags = *flags | 2;
    } else {
        *flags = *flags & 2;
    }

    return resultado;
}

uint8_t nand(uint8_t*a, uint8_t*b, uint8_t*flags){
    uint8_t resultado = 0;

    resultado = *a && *b; //nand

    //acualizamos las flags
    if(resultado == 0){
        *flags = *flags | 1;
    } else {
        *flags = *flags & 1;
    }

    return resultado;
}


void cpu_reset(CPU *cpu){
    cpu->pc = 0;
    cpu->outa = 0;
    cpu->outb = 0;
    cpu->jmp = 0;
    cpu->opcode = 0;
}
