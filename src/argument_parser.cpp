#include <iostream>
#include <stdio.h>
#include <string.h>
#include "../include/argument_parser.hpp"

void get_arguments(Arguments *arguments, int *argc, char *argv[]){
    for(int i = 0; i < *argc; i++){
        
        //std::cout << argv[i] << std::endl;//debug
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

        else if(strcmp("--show_registers", argv[i]) == 0){
            arguments->show_registers = true;
        }

        else{
            arguments->step = false;
            arguments->show_registers = false;    
        }

    }
}
