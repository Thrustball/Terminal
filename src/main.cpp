#include "termlib.h"
#include <iostream>
#include <unistd.h>



int main() {
	// int x = 0, y = 0;
	// char c = ' ';
	termlib te(80,23);
	te.fillScreen(' ');
	te.circle(40,10,7,0.6,'O');
	te.draw();
	return 0;
}
