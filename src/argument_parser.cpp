#include <iostream>
#include <stdio.h>
#include <string.h>
#include "../include/argument_parser.hpp"

void get_arguments(Arguments *arguments, int *argc, char *argv[]){

	if(*argv == NULL){
		return;
	}

	init_arguments(arguments);

    for(int i = 1; i < *argc; i++){

        std::cout << argv[i] << std::endl; //debug
        if(strcmp("--program", argv[i]) == 0){
            i++;
            arguments->program_path = argv[i];
        }

        else if(strcmp("--show_registers", argv[i]) == 0){
            arguments->show_registers = true;
        }

        else if(strcmp("--step", argv[i]) == 0){
            arguments->step = true;
        }

		else if((strcmp("-v", argv[i]) == 0) || (strcmp("--version", argv[i]) == 0 )){
			printf("alpha\n");
			exit(0);
		}

        else{
			//printf("Argumento: '%s' invalido \n", argv[i]);

			exit(1);
        }

    }
}

void init_arguments(Arguments *arguments){
	arguments->step = false;
	arguments->show_registers = false;
}
