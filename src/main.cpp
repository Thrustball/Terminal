#include "termlib.h"
#include <iostream>
#include <unistd.h>



int main() {
	// int x = 0, y = 0;
	// char c = ' ';
	termlib te(80,23);
	te.fillScreen(' ');
	te.rect(10, 5, 70, 20, '#');
	te.draw();

	return 0;
}
