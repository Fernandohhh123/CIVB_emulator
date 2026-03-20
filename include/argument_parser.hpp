#pragma once
#include <cstdint>

typedef struct{
    char *program_path;
    bool step;
    bool show_registers;
}Arguments;

void get_arguments(Arguments*, int*, char*argv[]);
