#ifndef SRC_TERMLIB_H_
#define SRC_TERMLIB_H_
#define PI 3.141592653589
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class termlib {
public:
	termlib(int, int);
	virtual ~termlib();
	void fillScreen(char);
	void clearScreen();
	void line(int, int, int, int, char);
	void draw();
	void setChar(int, int, char);
	void rect(int, int, int, int, char);
	void rectFill(int, int, int, int, char);
	void circle(int, int, int, float, char);


private:
	int rows;
	int columns;
	char** screen;
	void setHorizontalLine(int, int, int, char);
	void setVerticalLine(int, int, int, char);
	void checkIfInScreen(int,int);
	void checkIfInScreen(int,int,int,int);



};

#endif /* SRC_TERMLIB_H_ */
