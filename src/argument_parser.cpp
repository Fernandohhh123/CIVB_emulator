#include <iostream>
#include <string.h>
#include "../include/argument_parser.hpp"

void get_arguments(Arguments *arguments, int *argc, char *argv[]){
    for(int i = 0; i < *argc; i++){

        //std::cout << argv[i] << std::endl;//debug
        if(strcmp("--program", argv[i]) == 0){
            ++i;
            arguments->program_path = argv[i];
        }


    }
}
