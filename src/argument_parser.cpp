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

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "../include/argument_parser.hpp"

void get_arguments(Arguments *arguments, int *argc, char *argv[]){

	if(*argv == NULL){
		return;
	}

	if(*argc < 1){
		perror("Faltan argumentos.");
		printf("Use <-h | --help> para obtener ayuda.\n");
		exit(1);
	}

	init_arguments(arguments);

    for(int i = 1; i < *argc; i++){

		if((strcmp("--program", argv[i]) == 0) || (strcmp("-p", argv[i]) == 0)){
            i++;
			if(argv[i] == NULL){
				perror("No se especifico ruta del programa.\n");
				perror("Modo de uso: -p <ruta/al/programa.bin>.\n");
				exit(1);
			}

            arguments->program_path = argv[i];
        }

		else if((strcmp("-v", argv[i]) == 0) || (strcmp("--version", argv[i]) == 0 )){
			printf("Version: 0.0.1\n");
			exit(0);
		}

		else if((strcmp("-h", argv[i]) == 0) || (strcmp("--help", argv[i]) == 0 )){
// ---------------------------------
			printf("# Modo de uso #\n\
    -p [programa.bin] | --program [programa.bin]\n\
    -v | --version     Muestra la version del software\n\
    -h | --help        Muestra informacion de ayuda\n\
# Como usar #\n\
    - Para moverse por el menu use las teclas:\n\
    J Arriba\n\
    K Abajo\n\
    L Seleccionar\n\
- El emulador tiene atajos:\n\
    S Step\n\
    R Reset\n\
    N, M Scroll de las instrucciones\n\
    Q Salir\n\
    H Ayuda\n");
// --------------------------------
        		    exit(0);
		}

        else{
			printf("Argumento: '%s' invalido.\n", argv[i]);
			printf("Use <-h | --help> para obtener ayuda.\n");
			exit(1);
        }
    }
}

void init_arguments(Arguments *arguments){
	arguments->step = false;
	arguments->show_registers = false;
}
