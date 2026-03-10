#include <fstream>
#include <iostream>
#include <cstdint>
#include "../include/rom.hpp"
#include "../include/argument_parser.hpp"

std::vector<uint8_t> get_program_code(char *program_path){
    //abrimos el archivo para su lectura binaria
    std::ifstream archivo(program_path, std::ios::binary | std::ios::ate);

    if(!archivo.is_open()){
        std::cerr << "No se pudo abrir el programa." << std::endl;
    }

    std::streamsize tamanio = archivo.tellg();
    archivo.seekg(0, std::ios::beg);

    std::vector<uint8_t> code(tamanio);

    if(archivo.read(reinterpret_cast<char*>(code.data()), tamanio)){
        std::cout << "Programa cargado." << std::endl;
    }else{
        std::cerr << "No se pudo cargar el programa a rom." << std::endl;
    }

    archivo.close();

    return code;
}

