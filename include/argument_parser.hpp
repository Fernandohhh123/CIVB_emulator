#pragma once
#include <cstdint>

typedef struct{
    char *program_path;
}Arguments;

void get_arguments(Arguments*, int*, char*argv[]);
