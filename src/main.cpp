#include "termlib.h"
#include <iostream>
#include <unistd.h>



int main() {
	// int x = 0, y = 0;
	// char c = ' ';
	termlib te(113,23);
	te.fillScreen(' ');
	// te.rect(10, 5, 70, 20, '#');
	int x = 10;
	for(int i = 0; i < 93; i++) {
	te.circle(x+i, 10, 10, .6, '#');
	te.draw();
	usleep(100000);
	te.clearScreen();
	}
	return 0;
}
