#pragma once
#include <cstdint>


enum class Instruction : uint8_t{
    NOT = 0x00,
    NAND = 0x1,
    ADD = 0x2,
    LDA = 0x03,
    OUTA = 0x4,
    OUTB = 0x5,
    INA = 0x6,
    RD = 0x7,
    RA = 0x8,
    LDRA = 0x9,
    JPI = 0xC,
    JPC = 0xD,
    JPZ = 0xE
};
