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
