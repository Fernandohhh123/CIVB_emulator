#include <fstream>
#include <iostream>
#include <cstdint>
#include "../include/rom.hpp"
#include "../include/argument_parser.hpp"



// Se debe modificar la rom, ya no sera dinamica segun el tamanno del programa
// sera una memoria estatica de 8kb
void load_program_to_rom(ROM *rom, char *pgogram_path){

	FILE *program_code = fopen(program_path, "rb");

	if(program_code == NULL){
		perror("No se pudo abrir el archivo: %s", program_path);
		exit(1);
	}

	// Vamos al final del archivo para saber su tamanno
	fseek();

	fread(rom -> );

}
