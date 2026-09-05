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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include "../include/kbhit.hpp"

int kbhit(void){
	struct termios oldt, newt;
	int ch;
	int oldf;

	// 1. Obtener los atributos actuales de la terminal
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;

	// 2. Desactivar el modo canónico (ICANON) y el eco (ECHO)
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);

	// 3. Configurar la lectura de stdin para que sea NO bloqueante
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	// 4. Intentar leer un carácter
	ch = getchar();

	// 5. Restaurar la configuración original de la terminal y flags
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	// 6. Si leímos algo, devolver 1 (verdadero). Si no, devolver 0.
	if (ch != EOF) {
		ungetc(ch, stdin); // Devuelve el carácter al búfer para que pueda ser leído con getchar() luego
		return 1;
	}

	return 0;
}
