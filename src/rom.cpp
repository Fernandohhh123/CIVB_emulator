/*
civb - TUI based 4 bit cpu emulator

    Copyright (C) 2026 Fernando Hernández Valverde

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

    contact: fernandohdzvalverde@gmail.com
*/

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
		perror("Archivo de programa vacio.\n");
		perror("Use <-h | --help> para obtener ayuda.\n");
		exit(1);
	}

	// Vamos al final del archivo para saber su tamanno
	fseek(program_code, 0,SEEK_END);

	int program_size = ftell(program_code);

	if(program_size >= 0x2000){
		perror("El archivo supera los 8191 Bytes");
		exit(1);
	}

	fseek(program_code, 0,SEEK_SET);

	fread(rom -> program_instructions, 1, 8192, program_code);

	fclose(program_code);
}
