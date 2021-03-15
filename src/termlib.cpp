#include "termlib.h"


termlib::termlib(int r, int c) {
	rows = r;
	columns = c;
    //Dynamically allocating row space in heap
	screen = new char*[rows];
    //Dynamically allocating column space in heap
    for(int i=0; i<rows; i++){
    	screen[i] = new char[columns];
    }

    clearScreen();

}

termlib::~termlib() {

}

void termlib::draw() {
	printf("\033[2J");
    for(int i = 0; i < columns; i++) {
    	for(int j = 0; j < rows; j++) {
    		printf("%c",screen[j][i]);
    	}
    	if (i != columns - 1) printf("\n");
    }
}

void termlib::clearScreen() {
    for(int i = 0; i < columns; i++) {
    	for(int j = 0; j < rows; j++) {
    		screen[j][i] = ' ';
    	}
    }
}

void termlib::fillScreen(char c) {
    for(int i = 0; i < columns; i++) {
    	for(int j = 0; j < rows; j++) {
    		screen[j][i] = c;
    	}
    }
}

void termlib::setChar(int x, int y, char c) {
	checkIfInScreen(x,y);
	screen[x][y] = c;
}


void termlib::line(int x1, int y1, int x2, int y2, char c) {
	float slope;
	// int tmp;

	checkIfInScreen(x1,y1,x2,y2);

	if(x1 == x2) setVerticalLine(y1, y2, x1, c);
	else if (y1 == y2) setHorizontalLine(x1, x2, y1, c);
	else {

		/* if(x2 > x1) {
			tmp = x1;
			x1 = x2;
			x2 = tmp;
		}

		if(y2 > y1) {
			tmp = x1;
			x1 = x2;
			x2 = tmp;
		}
	*/
		slope = ((float) y2 - (float) y1) / ((float) x2 - (float) x1);
		float y = (float) y1;
		for( ; x1 <= x2; x1++, y+=slope) {
			screen[x1][(int)round(y)] = c;
		}

	}
}

void termlib::rect(int x1, int y1, int x2, int y2, char c) {
	line(x1,y1,x2,y1,c);
	line(x1,y2,x2,y2,c);
	line(x2,y2,x2,y1,c);
	line(x1,y1,x1,y2,c);
}

void termlib::rectFill(int x1, int y1, int x2, int y2, char c) {
	checkIfInScreen(x1, y1, x2, y2);
	int temp;

	if(x2 < x1) {
		temp = x1;
		x1 = x2;
		x2 = temp;
	}

	if(y2 < y1) {
		temp = y1;
		y1 = y2;
		y2 = temp;
	}


	for(int i = y1; i <= y2; i++) {
		for(int j = x1; j <= x2; j++) {
			screen[j][i] = c;
		}
	}
}

// yMod, because Chars on Terminal are bigger in x than y
void termlib::circle(int x, int y, int r, float yMod, char c) {
	checkIfInScreen(x,y);
	int circleSteps = 360;
	int xc, yc;
	float rad;
	for(int i = 0; i < circleSteps; i++) {
		rad = (PI * (float)i) / 180.0f;
		xc = (int) round((float)r * cos(rad));
		yc = (int) round((float)r * sin(rad) * yMod);
		checkIfInScreen(xc,yc);
		screen[x+xc][y+yc] = c;
	}

}

void termlib::checkIfInScreen(int x, int y) {
	if(x >= rows || x < 0) {
		printf("X Coordinate outside screen!\n");
		exit(1);
	} else if (y >= columns || y < 0) {
		printf("Y Coordinate outside screen!\n");
		exit(1);
	}
}

void termlib::checkIfInScreen(int x1, int y1, int x2, int y2) {
	if((x1 >= rows || x1 < 0) || (x2 >= rows || x2 < 0)) {
		printf("X Coordinate outside screen!\n");
		exit(1);
	} else if ((y1 >= columns || y1 < 0) || (y2 >= columns || y2 < 0)) {
		printf("Y Coordinate outside screen!\n");
		exit(1);
	}
}

void termlib::setHorizontalLine(int x1, int x2, int y, char c) {
	int i, iMax;
	if(x1 < x2) {
		i = x1;
		iMax = x2;
	} else {
		i = x2;
		iMax = x1;
	}

	for( ; i <= iMax; i++) {
		screen[i][y] = c;
	}
}

void termlib::setVerticalLine(int y1, int y2, int x, char c) {
	int i, iMax;
	if(y1 < y2) {
		i = y1;
		iMax = y2;
	} else {
		i = y2;
		iMax = y1;
	}

	for( ; i <= iMax; i++) {
		screen[x][i] = c;
	}
}
