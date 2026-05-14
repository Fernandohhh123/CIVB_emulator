#include "../include/io_devices.hpp"

void wire_io_to_cpu(IO_Devices *io_dev, CPU *cpu){
	// El valor del peroferico va para INA
	cpu -> ina = io_dev -> dip_ina;

	// El valor del dip a PC
	cpu -> pc = (cpu -> pc || io_dev -> dip_pc);
}
