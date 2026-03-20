#include "../include/cpu.hpp"
#include <stdio.h>
#include <cstdlib>
#include "../include/control_unity.hpp"


constexpr uint8_t FLAG_ZERO = (1 << 0);
constexpr uint8_t FLAG_CARRY = (1 << 1);

uint8_t add(uint8_t* a, uint8_t* b, uint8_t *flags){
    uint8_t resultado = 0;
    resultado = *a + *b;

    //acualizamos las flags
    if((resultado >> 4) > 0){
        resultado = (resultado & 0x0F);
        
        // 2 = 00000010
        *flags = *flags | 2;
    } else {
        *flags = *flags & 1;
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
        *flags = *flags & 2;
    }

    return resultado;
}


void cpu_reset(CPU *cpu){
    cpu->pc = 0;
    cpu->outa = 0;
    cpu->outb = 0;
    cpu->jmp = 0;
    cpu->opcode = 0;
    cpu->flags = 0;
}

void show_flags(uint8_t *flags){
    if(*flags == 0){
        printf("00");
    }
    else if(*flags == 1){
        printf("0Z");
    }
    else if(*flags == 2){
        printf("C0");
    }
    else if(*flags == 3){
        printf("CZ");
    }
}

void main_loop(CPU *cpu, ROM *rom, Arguments *arguments){
        
    while(1){
        
        if(arguments->show_registers){
            printf("FLAGS: ");
            show_flags(&cpu->flags);
            printf("\n");
            
            printf("PC: %x\n", cpu->pc);
            printf("ACC: %x\n", cpu->acc);
            printf("OUTA: %x\n", cpu->outa);
            printf("OUTB: %x\n", cpu->outb);
            printf("INA: %x\n", cpu->ina);
            printf("RA: %x\n", cpu->ra);
            printf("RD: %x\n", cpu->rd);
            printf("\n");
        }
        else{
            printf("PC: %d\n", cpu->pc);
            printf("b: %x ", cpu->outb);
            printf("a: %x\n", cpu->outa);
            printf("\n");
        }
        
        if(arguments->step){
            printf("ENTER para continuar...\n");
            getchar();
           
        }

        fetch_cycle(cpu, rom);
        
        execute_instruction(cpu);

        if(rom->address >= rom->program_instructions.size()){
            exit(0);
        }    
    }

}
