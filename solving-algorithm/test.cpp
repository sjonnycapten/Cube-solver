#include "stdafx.h"
#include "test.h"



void test::run(Algoritme* a)
{
	a->colourMap[0][0] = YELLOW;
	a->colourMap[1][0] = BLUE;
	a->colourMap[2][0] = GREEN;
	a->colourMap[3][0] = RED;
	a->colourMap[4][0] = BLUE;
	a->colourMap[5][0] = BLUE;
	a->colourMap[6][0] = GREEN;
	a->colourMap[7][0] = RED;
	a->colourMap[8][0] = YELLOW;
	 					 
	a->colourMap[0][1] = BLUE;
	a->colourMap[1][1] = WHITE;
	a->colourMap[2][1] = WHITE;
	a->colourMap[3][1] = ORANGE;
	a->colourMap[4][1] = ORANGE;
	a->colourMap[5][1] = WHITE;
	a->colourMap[6][1] = GREEN;
	a->colourMap[7][1] = GREEN;
	a->colourMap[8][1] = WHITE;
	 					 
	a->colourMap[0][2] = ORANGE;
	a->colourMap[1][2] = YELLOW;
	a->colourMap[2][2] = BLUE;
	a->colourMap[3][2] = ORANGE;
	a->colourMap[4][2] = WHITE;
	a->colourMap[5][2] = GREEN;
	a->colourMap[6][2] = RED;
	a->colourMap[7][2] = ORANGE;
	a->colourMap[8][2] = WHITE;
	 					 
	a->colourMap[0][3] = RED;
	a->colourMap[1][3] = WHITE;
	a->colourMap[2][3] = ORANGE;
	a->colourMap[3][3] = WHITE;
	a->colourMap[4][3] = RED;
	a->colourMap[5][3] = BLUE;
	a->colourMap[6][3] = ORANGE;
	a->colourMap[7][3] = GREEN;
	a->colourMap[8][3] = BLUE;
	 					 
	a->colourMap[0][4] = YELLOW;
	a->colourMap[1][4] = YELLOW;
	a->colourMap[2][4] = ORANGE;
	a->colourMap[3][4] = ORANGE;
	a->colourMap[4][4] = YELLOW;
	a->colourMap[5][4] = YELLOW;
	a->colourMap[6][4] = RED;
	a->colourMap[7][4] = RED;
	a->colourMap[8][4] = YELLOW;
	 					 
	a->colourMap[0][5] = GREEN;
	a->colourMap[1][5] = GREEN;
	a->colourMap[2][5] = BLUE;
	a->colourMap[3][5] = YELLOW;
	a->colourMap[4][5] = GREEN;
	a->colourMap[5][5] = RED;
	a->colourMap[6][5] = RED;
	a->colourMap[7][5] = BLUE;
	a->colourMap[8][5] = WHITE;
	 
	a->colourMap[0][6] = UNKNOWN;
}
