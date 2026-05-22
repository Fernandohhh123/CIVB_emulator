#include <fstream>
#include <iostream>
#include <cstdint>
#include "../include/rom.hpp"
#include "../include/argument_parser.hpp"



// Se debe modificar la rom, ya no sera dinamica segun el tamanno del programa
// sera una memoria estatica de 8kb
void load_program_to_rom(ROM *rom, char *program_path){

	// Se abre el archivo con el programa
	FILE *program_code = fopen(program_path, "rb");

	if(program_code == NULL){
		perror("No se pudo abrir el archivo del programa.");
		exit(1);
	}

	// Vamos al final del archivo para saber su tamanno
	fseek(program_code, 0,SEEK_END);

	int program_size = ftell(program_code);

	if(program_size >= 0x2000){
		perror("El archivo supera los 8191 Bytes");
		exit(1);
	}

	fread(rom -> program_instructions, sizeof(uint8_t), program_size, program_code);

	fclose(program_code);
}
