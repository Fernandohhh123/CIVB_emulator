#include <stdio.h>
#include "gotoxy.hpp"


void gotoxy(int x, int y){
	printf("\033[%d;%dH", y + 1, x + 1);
}
