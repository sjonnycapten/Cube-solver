#include "Algoritme.h"

void Algoritme::run()
{
	init();
	downCrossAlgorithm();
	firstLayerAlgorithm();
	secondLayerAlgorithm();
	upCrossAlgorithm();
	thirdLayerAlgorithm();
	upCornerAlgorithm();
	upMiddleAlgorithm();
	printMap();
	optimizeSolution();
	printSolution();
}

void Algoritme::init()
{
	// reset solution array and index
	int x;
	for (x = 0; x < SOLUTION_AMOUNT; x++)
		solutions[x] = EMPTY;
	*solutionIndex = 0;

	// all cubiemap items will be filled with pointers to the right place on the colourmap
	// (0, 0) - (0, 19)
	cubieMap[0][0][0] = 1;
	cubieMap[0][0][1] = 0;

	cubieMap[0][1][0] = 5;
	cubieMap[0][1][1] = 0;

	cubieMap[0][2][0] = 7;
	cubieMap[0][2][1] = 0;

	cubieMap[0][3][0] = 3;
	cubieMap[0][3][1] = 0;

	cubieMap[0][4][0] = 3;
	cubieMap[0][4][1] = 1;

	cubieMap[0][5][0] = 5;
	cubieMap[0][5][1] = 3;

	cubieMap[0][6][0] = 5;
	cubieMap[0][6][1] = 1;

	cubieMap[0][7][0] = 3;
	cubieMap[0][7][1] = 3;

	cubieMap[0][8][0] = 7;
	cubieMap[0][8][1] = 5;

	cubieMap[0][9][0] = 5;
	cubieMap[0][9][1] = 5;

	cubieMap[0][10][0] = 1;
	cubieMap[0][10][1] = 5;

	cubieMap[0][11][0] = 3;
	cubieMap[0][11][1] = 5;

	cubieMap[0][12][0] = 0;
	cubieMap[0][12][1] = 0;

	cubieMap[0][13][0] = 2;
	cubieMap[0][13][1] = 0;

	cubieMap[0][14][0] = 6;
	cubieMap[0][14][1] = 0;

	cubieMap[0][15][0] = 8;
	cubieMap[0][15][1] = 0;

	cubieMap[0][16][0] = 6;
	cubieMap[0][16][1] = 5;

	cubieMap[0][17][0] = 8;
	cubieMap[0][17][1] = 5;

	cubieMap[0][18][0] = 0;
	cubieMap[0][18][1] = 5;

	cubieMap[0][19][0] = 2;
	cubieMap[0][19][1] = 5;

	// (1, 0) - (1, 19)
	cubieMap[1][0][0] = 1;
	cubieMap[1][0][1] = 4;

	cubieMap[1][1][0] = 1;
	cubieMap[1][1][1] = 3;

	cubieMap[1][2][0] = 1;
	cubieMap[1][2][1] = 2;

	cubieMap[1][3][0] = 1;
	cubieMap[1][3][1] = 1;

	cubieMap[1][4][0] = 5;
	cubieMap[1][4][1] = 4;

	cubieMap[1][5][0] = 3;
	cubieMap[1][5][1] = 4;

	cubieMap[1][6][0] = 3;
	cubieMap[1][6][1] = 2;

	cubieMap[1][7][0] = 5;
	cubieMap[1][7][1] = 2;

	cubieMap[1][8][0] = 7;
	cubieMap[1][8][1] = 4;

	cubieMap[1][9][0] = 7;
	cubieMap[1][9][1] = 3;

	cubieMap[1][10][0] = 7;
	cubieMap[1][10][1] = 2;

	cubieMap[1][11][0] = 7;
	cubieMap[1][11][1] = 1;

	cubieMap[1][12][0] = 0;
	cubieMap[1][12][1] = 1;

	cubieMap[1][13][0] = 2;
	cubieMap[1][13][1] = 3;

	cubieMap[1][14][0] = 2;
	cubieMap[1][14][1] = 1;

	cubieMap[1][15][0] = 0;
	cubieMap[1][15][1] = 3;

	cubieMap[1][16][0] = 6;
	cubieMap[1][16][1] = 1;

	cubieMap[1][17][0] = 8;
	cubieMap[1][17][1] = 3;

	cubieMap[1][18][0] = 8;
	cubieMap[1][18][1] = 1;

	cubieMap[1][19][0] = 6;
	cubieMap[1][19][1] = 3;

	// (2, 0) - (2, 19)
	cubieMap[2][0][0] = 0;
	cubieMap[2][0][1] = 6;

	cubieMap[2][1][0] = 0;
	cubieMap[2][1][1] = 6;

	cubieMap[2][2][0] = 0;
	cubieMap[2][2][1] = 6;

	cubieMap[2][3][0] = 0;
	cubieMap[2][3][1] = 6;

	cubieMap[2][4][0] = 0;
	cubieMap[2][4][1] = 6;

	cubieMap[2][5][0] = 0;
	cubieMap[2][5][1] = 6;

	cubieMap[2][6][0] = 0;
	cubieMap[2][6][1] = 6;

	cubieMap[2][7][0] = 0;
	cubieMap[2][7][1] = 6;

	cubieMap[2][8][0] = 0;
	cubieMap[2][8][1] = 6;

	cubieMap[2][9][0] = 0;
	cubieMap[2][9][1] = 6;

	cubieMap[2][10][0] = 0;
	cubieMap[2][10][1] = 6;

	cubieMap[2][11][0] = 0;
	cubieMap[2][11][1] = 6;

	cubieMap[2][12][0] = 2;
	cubieMap[2][12][1] = 4;

	cubieMap[2][13][0] = 0;
	cubieMap[2][13][1] = 4;

	cubieMap[2][14][0] = 0;
	cubieMap[2][14][1] = 2;

	cubieMap[2][15][0] = 2;
	cubieMap[2][15][1] = 2;

	cubieMap[2][16][0] = 8;
	cubieMap[2][16][1] = 4;

	cubieMap[2][17][0] = 6;
	cubieMap[2][17][1] = 4;

	cubieMap[2][18][0] = 6;
	cubieMap[2][18][1] = 2;

	cubieMap[2][19][0] = 8;
	cubieMap[2][19][1] = 2;
}

void Algoritme::optimizeSolution()
{
	int usedOps = 1;
	char tempSolutions[SOLUTION_AMOUNT];
	int x;
	int y;
	int temp = 0;
	while (usedOps != 0)
	{
		usedOps = 0;
		// optimize solution array
		int a;
		for (a = 0; a < SOLUTION_AMOUNT; a++)
			tempSolutions[a] = EMPTY;

		temp = 0;
		for (x = 0; x < SOLUTION_AMOUNT; x++)
		{
			// when 2 contradirections are after each other, remove them
			if ((solutions[x] == RIGHT && solutions[x + 1] == RIGHTa) ||
				(solutions[x] == RIGHTa && solutions[x + 1] == RIGHT) ||
				(solutions[x] == LEFT && solutions[x + 1] == LEFTa) ||
				(solutions[x] == LEFTa && solutions[x + 1] == LEFT) ||
				(solutions[x] == UP && solutions[x + 1] == UPa) ||
				(solutions[x] == UPa && solutions[x + 1] == UP) ||
				(solutions[x] == DOWN && solutions[x + 1] == DOWNa) ||
				(solutions[x] == DOWNa && solutions[x + 1] == DOWN) ||
				(solutions[x] == FRONT && solutions[x + 1] == FRONTa) ||
				(solutions[x] == FRONTa && solutions[x + 1] == FRONT) ||
				(solutions[x] == BACK && solutions[x + 1] == BACKa) ||
				(solutions[x] == BACKa && solutions[x + 1] == BACK))
			{
				x++;
				usedOps++;
			}
			// when 4 of the same moves are after each other, remove them
			else if (solutions[x] == solutions[x + 1] && solutions[x] == solutions[x + 2] && solutions[x] == solutions[x + 3] && solutions[x] != 'E')
			{
				x += 3;
				usedOps++;
			}
			// when 3 of the same moves ar after each other, replace with contramove
			else if (solutions[x] == solutions[x + 1] && solutions[x] == solutions[x + 2] && solutions[x] != 'E')
			{
				// RIGHT
				if (solutions[x] == RIGHT)
					tempSolutions[temp] = RIGHTa;
				// RIGHTa
				if (solutions[x] == RIGHTa)
					tempSolutions[temp] = RIGHT;
				// LEFT
				if (solutions[x] == LEFT)
					tempSolutions[temp] = LEFTa;
				// LEFTa
				if (solutions[x] == LEFTa)
					tempSolutions[temp] = LEFT;
				// UP
				if (solutions[x] == UP)
					tempSolutions[temp] = UPa;
				// UPa
				if (solutions[x] == UPa)
					tempSolutions[temp] = UP;
				// DOWN
				if (solutions[x] == DOWN)
					tempSolutions[temp] = DOWNa;
				// DOWNa
				if (solutions[x] == DOWNa)
					tempSolutions[temp] = DOWN;
				// FRONT
				if (solutions[x] == FRONT)
					tempSolutions[temp] = FRONTa;
				// FRONTa
				if (solutions[x] == FRONTa)
					tempSolutions[temp] = FRONT;
				// BACK
				if (solutions[x] == BACK)
					tempSolutions[temp] = BACKa;
				// BACKa
				if (solutions[x] == BACKa)
					tempSolutions[temp] = BACK;

				temp++;
				x += 2;
				usedOps++;
			}
			// fill array with empty items
			else if (solutions[x] == EMPTY)
			{
				tempSolutions[temp] = EMPTY;
				temp++;
			}
			// fill array with right solution
			else
			{
				tempSolutions[temp] = solutions[x];
				temp++;
			}
		}
		// fully copy temp solution to solutions;
		for (y = 0; y < SOLUTION_AMOUNT; y++)
			solutions[y] = tempSolutions[y];
	}
}

void Algoritme::printMap()
{
	int x = 0;
	int y = 0;

	for (y = 0; y < 6; y++)
	{
		for (x = 0; x < 9; x++)
		{
			if (x % 3 == 0)
			{
				printf("\n");
			}
			printf("%c  ", colourMap[x][y]);
		}
		printf("\n\n");
	}
}

void Algoritme::printCubieMap()
{
	int x;
	int y;
	for (y = 0; y < 12; y++)
	{
		for (x = 0; x < 3; x++)
		{
			printf("%c  ", colourMap[cubieMap[x][y][0]][cubieMap[x][y][1]]);
		}
		printf("\n");
	}
}

void Algoritme::printArray()
{
	int x;
	int y;

	for (y = 0; y < COLOUR_MAP_Y - 1; y++)
	{
		for (x = 0; x < COLOUR_MAP_X; x++)
		{
			switch (colourMap[x][y])
			{
			case '0':
				printf("B");
				break;
			case '1':
				printf("O");
				break;
			case '2':
				printf("W");
				break;
			case '3':
				printf("R");
				break;
			case '4':
				printf("Y");
				break;
			case '5':
				printf("G");
				break;
			}
		}
		printf("\n");
	}
}

void Algoritme::printSolution()
{
	int z;
	for (z = 0; z < SOLUTION_AMOUNT; z++)
	{
		if (solutions[z] != EMPTY)
			printf("%c ", solutions[z]);
	}
}

void Algoritme::rightCW()
{
	int x;
	int y;

	// creating temporary array
	char tempColourMap[COLOUR_MAP_X][COLOUR_MAP_Y];
	for (x = 0; x < COLOUR_MAP_X; x++)
	{
		for (y = 0; y < COLOUR_MAP_Y; y++)
		{
			tempColourMap[x][y] = colourMap[x][y];
		}
	}
	// algorithm for r

	// U
	colourMap[2][0] = tempColourMap[2][2];
	colourMap[5][0] = tempColourMap[5][2];
	colourMap[8][0] = tempColourMap[8][2];

	// F
	colourMap[2][2] = tempColourMap[2][5];
	colourMap[5][2] = tempColourMap[5][5];
	colourMap[8][2] = tempColourMap[8][5];

	// R
	colourMap[0][3] = tempColourMap[6][3];
	colourMap[1][3] = tempColourMap[3][3];
	colourMap[2][3] = tempColourMap[0][3];
	colourMap[3][3] = tempColourMap[7][3];
	colourMap[5][3] = tempColourMap[1][3];
	colourMap[6][3] = tempColourMap[8][3];
	colourMap[7][3] = tempColourMap[5][3];
	colourMap[8][3] = tempColourMap[2][3];

	// B
	colourMap[0][4] = tempColourMap[8][0];
	colourMap[3][4] = tempColourMap[5][0];
	colourMap[6][4] = tempColourMap[2][0];

	// D
	colourMap[2][5] = tempColourMap[6][4];
	colourMap[5][5] = tempColourMap[3][4];
	colourMap[8][5] = tempColourMap[0][4];
}

void Algoritme::rightCCW()
{
	int x;
	int y;

	// creating temporary array
	char tempColourMap[COLOUR_MAP_X][COLOUR_MAP_Y];
	for (x = 0; x < COLOUR_MAP_X; x++)
	{
		for (y = 0; y < COLOUR_MAP_Y; y++)
		{
			tempColourMap[x][y] = colourMap[x][y];
		}
	}
	// algorithm for r'

	// U
	colourMap[2][0] = tempColourMap[6][4];
	colourMap[5][0] = tempColourMap[3][4];
	colourMap[8][0] = tempColourMap[0][4];

	// F
	colourMap[2][2] = tempColourMap[2][0];
	colourMap[5][2] = tempColourMap[5][0];
	colourMap[8][2] = tempColourMap[8][0];

	// R
	colourMap[0][3] = tempColourMap[2][3];
	colourMap[1][3] = tempColourMap[5][3];
	colourMap[2][3] = tempColourMap[8][3];
	colourMap[3][3] = tempColourMap[1][3];
	colourMap[5][3] = tempColourMap[7][3];
	colourMap[6][3] = tempColourMap[0][3];
	colourMap[7][3] = tempColourMap[3][3];
	colourMap[8][3] = tempColourMap[6][3];

	// B
	colourMap[0][4] = tempColourMap[8][5];
	colourMap[3][4] = tempColourMap[5][5];
	colourMap[6][4] = tempColourMap[2][5];

	// D
	colourMap[2][5] = tempColourMap[2][2];
	colourMap[5][5] = tempColourMap[5][2];
	colourMap[8][5] = tempColourMap[8][2];
}

void Algoritme::leftCW()
{
	int x;
	int y;

	// creating temporary array
	char tempColourMap[COLOUR_MAP_X][COLOUR_MAP_Y];
	for (x = 0; x < COLOUR_MAP_X; x++)
	{
		for (y = 0; y < COLOUR_MAP_Y; y++)
		{
			tempColourMap[x][y] = colourMap[x][y];
		}
	}
	// algorithm for l

	// U
	colourMap[0][0] = tempColourMap[8][4];
	colourMap[3][0] = tempColourMap[5][4];
	colourMap[6][0] = tempColourMap[2][4];

	// L
	colourMap[0][1] = tempColourMap[6][1];
	colourMap[1][1] = tempColourMap[3][1];
	colourMap[2][1] = tempColourMap[0][1];
	colourMap[3][1] = tempColourMap[7][1];
	colourMap[5][1] = tempColourMap[1][1];
	colourMap[6][1] = tempColourMap[8][1];
	colourMap[7][1] = tempColourMap[5][1];
	colourMap[8][1] = tempColourMap[2][1];

	// F
	colourMap[0][2] = tempColourMap[0][0];
	colourMap[3][2] = tempColourMap[3][0];
	colourMap[6][2] = tempColourMap[6][0];

	// B
	colourMap[2][4] = tempColourMap[6][5];
	colourMap[5][4] = tempColourMap[3][5];
	colourMap[8][4] = tempColourMap[0][5];

	// D
	colourMap[0][5] = tempColourMap[0][2];
	colourMap[3][5] = tempColourMap[3][2];
	colourMap[6][5] = tempColourMap[6][2];
}

void Algoritme::leftCCW()
{
	int x;
	int y;

	// creating temporary array
	char tempColourMap[COLOUR_MAP_X][COLOUR_MAP_Y];
	for (x = 0; x < COLOUR_MAP_X; x++)
	{
		for (y = 0; y < COLOUR_MAP_Y; y++)
		{
			tempColourMap[x][y] = colourMap[x][y];
		}
	}
	// algorithm for l'

	// U
	colourMap[0][0] = tempColourMap[0][2];
	colourMap[3][0] = tempColourMap[3][2];
	colourMap[6][0] = tempColourMap[6][2];

	// L
	colourMap[0][1] = tempColourMap[2][1];
	colourMap[1][1] = tempColourMap[5][1];
	colourMap[2][1] = tempColourMap[8][1];
	colourMap[3][1] = tempColourMap[1][1];
	colourMap[5][1] = tempColourMap[7][1];
	colourMap[6][1] = tempColourMap[0][1];
	colourMap[7][1] = tempColourMap[3][1];
	colourMap[8][1] = tempColourMap[6][1];

	// F
	colourMap[0][2] = tempColourMap[0][5];
	colourMap[3][2] = tempColourMap[3][5];
	colourMap[6][2] = tempColourMap[6][5];

	// B
	colourMap[2][4] = tempColourMap[6][0];
	colourMap[5][4] = tempColourMap[3][0];
	colourMap[8][4] = tempColourMap[0][0];

	// D
	colourMap[0][5] = tempColourMap[8][4];
	colourMap[3][5] = tempColourMap[5][4];
	colourMap[6][5] = tempColourMap[2][4];
}

void Algoritme::upCW()
{
	int x;
	int y;

	// creating temporary array
	char tempColourMap[COLOUR_MAP_X][COLOUR_MAP_Y];
	for (x = 0; x < COLOUR_MAP_X; x++)
	{
		for (y = 0; y < COLOUR_MAP_Y; y++)
		{
			tempColourMap[x][y] = colourMap[x][y];
		}
	}
	// algorithm for u

	// U
	colourMap[0][0] = tempColourMap[6][0];
	colourMap[1][0] = tempColourMap[3][0];
	colourMap[2][0] = tempColourMap[0][0];
	colourMap[3][0] = tempColourMap[7][0];
	colourMap[5][0] = tempColourMap[1][0];
	colourMap[6][0] = tempColourMap[8][0];
	colourMap[7][0] = tempColourMap[5][0];
	colourMap[8][0] = tempColourMap[2][0];

	// L
	colourMap[0][1] = tempColourMap[0][2];
	colourMap[1][1] = tempColourMap[1][2];
	colourMap[2][1] = tempColourMap[2][2];

	// F
	colourMap[0][2] = tempColourMap[0][3];
	colourMap[1][2] = tempColourMap[1][3];
	colourMap[2][2] = tempColourMap[2][3];

	// R
	colourMap[0][3] = tempColourMap[0][4];
	colourMap[1][3] = tempColourMap[1][4];
	colourMap[2][3] = tempColourMap[2][4];

	// B
	colourMap[0][4] = tempColourMap[0][1];
	colourMap[1][4] = tempColourMap[1][1];
	colourMap[2][4] = tempColourMap[2][1];
}

void Algoritme::upCCW()
{
	int x;
	int y;

	// creating temporary array
	char tempColourMap[COLOUR_MAP_X][COLOUR_MAP_Y];
	for (x = 0; x < COLOUR_MAP_X; x++)
	{
		for (y = 0; y < COLOUR_MAP_Y; y++)
		{
			tempColourMap[x][y] = colourMap[x][y];
		}
	}
	// algorithm for u'

	// U
	colourMap[0][0] = tempColourMap[2][0];
	colourMap[1][0] = tempColourMap[5][0];
	colourMap[2][0] = tempColourMap[8][0];
	colourMap[3][0] = tempColourMap[1][0];
	colourMap[5][0] = tempColourMap[7][0];
	colourMap[6][0] = tempColourMap[0][0];
	colourMap[7][0] = tempColourMap[3][0];
	colourMap[8][0] = tempColourMap[6][0];

	// L
	colourMap[0][1] = tempColourMap[0][4];
	colourMap[1][1] = tempColourMap[1][4];
	colourMap[2][1] = tempColourMap[2][4];

	// F
	colourMap[0][2] = tempColourMap[0][1];
	colourMap[1][2] = tempColourMap[1][1];
	colourMap[2][2] = tempColourMap[2][1];

	// R
	colourMap[0][3] = tempColourMap[0][2];
	colourMap[1][3] = tempColourMap[1][2];
	colourMap[2][3] = tempColourMap[2][2];

	// B
	colourMap[0][4] = tempColourMap[0][3];
	colourMap[1][4] = tempColourMap[1][3];
	colourMap[2][4] = tempColourMap[2][3];
}

void Algoritme::downCW()
{
	int x;
	int y;

	// creating temporary array
	char tempColourMap[COLOUR_MAP_X][COLOUR_MAP_Y];
	for (x = 0; x < COLOUR_MAP_X; x++)
	{
		for (y = 0; y < COLOUR_MAP_Y; y++)
		{
			tempColourMap[x][y] = colourMap[x][y];
		}
	}
	// algorithm for d

	// L
	colourMap[6][1] = tempColourMap[6][4];
	colourMap[7][1] = tempColourMap[7][4];
	colourMap[8][1] = tempColourMap[8][4];

	// F
	colourMap[6][2] = tempColourMap[6][1];
	colourMap[7][2] = tempColourMap[7][1];
	colourMap[8][2] = tempColourMap[8][1];

	// R
	colourMap[6][3] = tempColourMap[6][2];
	colourMap[7][3] = tempColourMap[7][2];
	colourMap[8][3] = tempColourMap[8][2];

	// B
	colourMap[6][4] = tempColourMap[6][3];
	colourMap[7][4] = tempColourMap[7][3];
	colourMap[8][4] = tempColourMap[8][3];

	// D
	colourMap[0][5] = tempColourMap[6][5];
	colourMap[1][5] = tempColourMap[3][5];
	colourMap[2][5] = tempColourMap[0][5];
	colourMap[3][5] = tempColourMap[7][5];
	colourMap[5][5] = tempColourMap[1][5];
	colourMap[6][5] = tempColourMap[8][5];
	colourMap[7][5] = tempColourMap[5][5];
	colourMap[8][5] = tempColourMap[2][5];
}

void Algoritme::downCCW()
{
	int x;
	int y;

	// creating temporary array
	char tempColourMap[COLOUR_MAP_X][COLOUR_MAP_Y];
	for (x = 0; x < COLOUR_MAP_X; x++)
	{
		for (y = 0; y < COLOUR_MAP_Y; y++)
		{
			tempColourMap[x][y] = colourMap[x][y];
		}
	}
	// algorithm for d'

	// L
	colourMap[6][1] = tempColourMap[6][2];
	colourMap[7][1] = tempColourMap[7][2];
	colourMap[8][1] = tempColourMap[8][2];

	// F
	colourMap[6][2] = tempColourMap[6][3];
	colourMap[7][2] = tempColourMap[7][3];
	colourMap[8][2] = tempColourMap[8][3];

	// R
	colourMap[6][3] = tempColourMap[6][4];
	colourMap[7][3] = tempColourMap[7][4];
	colourMap[8][3] = tempColourMap[8][4];

	// B
	colourMap[6][4] = tempColourMap[6][1];
	colourMap[7][4] = tempColourMap[7][1];
	colourMap[8][4] = tempColourMap[8][1];

	// D
	colourMap[0][5] = tempColourMap[2][5];
	colourMap[1][5] = tempColourMap[5][5];
	colourMap[2][5] = tempColourMap[8][5];
	colourMap[3][5] = tempColourMap[1][5];
	colourMap[5][5] = tempColourMap[7][5];
	colourMap[6][5] = tempColourMap[0][5];
	colourMap[7][5] = tempColourMap[3][5];
	colourMap[8][5] = tempColourMap[6][5];
}

void Algoritme::frontCW()
{
	int x;
	int y;

	// creating temporary array
	char tempColourMap[COLOUR_MAP_X][COLOUR_MAP_Y];
	for (x = 0; x < COLOUR_MAP_X; x++)
	{
		for (y = 0; y < COLOUR_MAP_Y; y++)
		{
			tempColourMap[x][y] = colourMap[x][y];
		}
	}
	// algorithm for f

	// U
	colourMap[6][0] = tempColourMap[8][1];
	colourMap[7][0] = tempColourMap[5][1];
	colourMap[8][0] = tempColourMap[2][1];

	// L
	colourMap[2][1] = tempColourMap[0][5];
	colourMap[5][1] = tempColourMap[1][5];
	colourMap[8][1] = tempColourMap[2][5];

	// F
	colourMap[0][2] = tempColourMap[6][2];
	colourMap[1][2] = tempColourMap[3][2];
	colourMap[2][2] = tempColourMap[0][2];
	colourMap[3][2] = tempColourMap[7][2];
	colourMap[5][2] = tempColourMap[1][2];
	colourMap[6][2] = tempColourMap[8][2];
	colourMap[7][2] = tempColourMap[5][2];
	colourMap[8][2] = tempColourMap[2][2];

	// R
	colourMap[0][3] = tempColourMap[6][0];
	colourMap[3][3] = tempColourMap[7][0];
	colourMap[6][3] = tempColourMap[8][0];

	// D
	colourMap[0][5] = tempColourMap[6][3];
	colourMap[1][5] = tempColourMap[3][3];
	colourMap[2][5] = tempColourMap[0][3];
}

void Algoritme::frontCCW()
{
	int x;
	int y;

	// creating temporary array
	char tempColourMap[COLOUR_MAP_X][COLOUR_MAP_Y];
	for (x = 0; x < COLOUR_MAP_X; x++)
	{
		for (y = 0; y < COLOUR_MAP_Y; y++)
		{
			tempColourMap[x][y] = colourMap[x][y];
		}
	}
	// algorithm for f'

	// U
	colourMap[6][0] = tempColourMap[0][3];
	colourMap[7][0] = tempColourMap[3][3];
	colourMap[8][0] = tempColourMap[6][3];

	// L
	colourMap[2][1] = tempColourMap[8][0];
	colourMap[5][1] = tempColourMap[7][0];
	colourMap[8][1] = tempColourMap[6][0];

	// F
	colourMap[0][2] = tempColourMap[2][2];
	colourMap[1][2] = tempColourMap[5][2];
	colourMap[2][2] = tempColourMap[8][2];
	colourMap[3][2] = tempColourMap[1][2];
	colourMap[5][2] = tempColourMap[7][2];
	colourMap[6][2] = tempColourMap[0][2];
	colourMap[7][2] = tempColourMap[3][2];
	colourMap[8][2] = tempColourMap[6][2];

	// R
	colourMap[0][3] = tempColourMap[2][5];
	colourMap[3][3] = tempColourMap[1][5];
	colourMap[6][3] = tempColourMap[0][5];

	// D
	colourMap[0][5] = tempColourMap[2][1];
	colourMap[1][5] = tempColourMap[5][1];
	colourMap[2][5] = tempColourMap[8][1];
}

void Algoritme::backCW()
{
	int x;
	int y;

	// creating temporary array
	char tempColourMap[COLOUR_MAP_X][COLOUR_MAP_Y];
	for (x = 0; x < COLOUR_MAP_X; x++)
	{
		for (y = 0; y < COLOUR_MAP_Y; y++)
		{
			tempColourMap[x][y] = colourMap[x][y];
		}
	}
	// algorithm for b

	// U
	colourMap[0][0] = tempColourMap[2][3];
	colourMap[1][0] = tempColourMap[5][3];
	colourMap[2][0] = tempColourMap[8][3];

	// L
	colourMap[0][1] = tempColourMap[2][0];
	colourMap[3][1] = tempColourMap[1][0];
	colourMap[6][1] = tempColourMap[0][0];

	// R
	colourMap[2][3] = tempColourMap[8][5];
	colourMap[5][3] = tempColourMap[7][5];
	colourMap[8][3] = tempColourMap[6][5];

	// B
	colourMap[0][4] = tempColourMap[6][4];
	colourMap[1][4] = tempColourMap[3][4];
	colourMap[2][4] = tempColourMap[0][4];
	colourMap[3][4] = tempColourMap[7][4];
	colourMap[5][4] = tempColourMap[1][4];
	colourMap[6][4] = tempColourMap[8][4];
	colourMap[7][4] = tempColourMap[5][4];
	colourMap[8][4] = tempColourMap[2][4];

	// D
	colourMap[6][5] = tempColourMap[0][1];
	colourMap[7][5] = tempColourMap[3][1];
	colourMap[8][5] = tempColourMap[6][1];
}

void Algoritme::backCCW()
{
	int x;
	int y;

	// creating temporary array
	char tempColourMap[COLOUR_MAP_X][COLOUR_MAP_Y];
	for (x = 0; x < COLOUR_MAP_X; x++)
	{
		for (y = 0; y < COLOUR_MAP_Y; y++)
		{
			tempColourMap[x][y] = colourMap[x][y];
		}
	}
	// algorithm for b'

	// U
	colourMap[0][0] = tempColourMap[6][1];
	colourMap[1][0] = tempColourMap[3][1];
	colourMap[2][0] = tempColourMap[0][1];

	// L
	colourMap[0][1] = tempColourMap[6][5];
	colourMap[3][1] = tempColourMap[7][5];
	colourMap[6][1] = tempColourMap[8][5];

	// R
	colourMap[2][3] = tempColourMap[0][0];
	colourMap[5][3] = tempColourMap[1][0];
	colourMap[8][3] = tempColourMap[2][0];

	// B
	colourMap[0][4] = tempColourMap[2][4];
	colourMap[1][4] = tempColourMap[5][4];
	colourMap[2][4] = tempColourMap[8][4];
	colourMap[3][4] = tempColourMap[1][4];
	colourMap[5][4] = tempColourMap[7][4];
	colourMap[6][4] = tempColourMap[0][4];
	colourMap[7][4] = tempColourMap[3][4];
	colourMap[8][4] = tempColourMap[6][4];

	// D
	colourMap[6][5] = tempColourMap[8][3];
	colourMap[7][5] = tempColourMap[5][3];
	colourMap[8][5] = tempColourMap[2][3];
}

void Algoritme::downCrossAlgorithm()
{
	// variables to check if cross items are solved
	uint8_t DB = 0; // square DownBack
	uint8_t DR = 0; // square DownRight
	uint8_t DF = 0; // square DownFront
	uint8_t DL = 0; // square DownLeft

	while (DB != 1 || DR != 1 || DF != 1 || DL != 1)
	{
		// check if cross is already solved
		if (colourMap[7][5] == GREEN && colourMap[7][4] == YELLOW)
			DB = 1;
		else
			DB = 0;

		if (colourMap[5][5] == GREEN && colourMap[7][3] == RED)
			DR = 1;
		else
			DR = 0;

		if (colourMap[1][5] == GREEN && colourMap[7][2] == WHITE)
			DF = 1;
		else
			DF = 0;

		if (colourMap[3][5] == GREEN && colourMap[7][1] == ORANGE)
			DL = 1;
		else
			DL = 0;

		// if not all cross items are solved, solve them
		if (DB != 1 || DR != 1 || DF != 1 || DL != 1)
		{
			// check edge pieces on green square
			int y;
			char color;
			int green;
			for (y = 0; y < 12; y++)
			{
				// if one of the squares is green and cross is not solved, move cube
				if ((colourMap[cubieMap[0][y][0]][cubieMap[0][y][1]] == GREEN || colourMap[cubieMap[1][y][0]][cubieMap[1][y][1]] == GREEN) && (DB != 1 || DR != 1 || DF != 1 || DL != 1))
				{
					printf("%d %d %d %d %d\n", DB, DR, DF, DL, y);
					// check the color of the !green-square
					if (colourMap[cubieMap[1][y][0]][cubieMap[1][y][1]] == GREEN)
					{
						color = colourMap[cubieMap[0][y][0]][cubieMap[0][y][1]];
						green = 1;
					}
					else
					{
						color = colourMap[cubieMap[1][y][0]][cubieMap[1][y][1]];
						green = 0;
					}

					int yValue = cubieMap[1][y][1];
					int xValue = color - '0';
					switch (y)
					{
						// move square from top layer
						// UB
					case 0:
						// UR
					case 1:
						// UF
					case 2:
						// UL
					case 3:
						// turn cube untill the !green-square is above its middle-square
						while (xValue != yValue) {
							upCCW();
							solutions[*solutionIndex] = UPa;
							*solutionIndex += 1;
							if (yValue < 4)
								yValue += 1;
							else
								yValue = 1;
						}
						// check if green-square is on top of the cube then turn cube to cross
						if (!cubieMap[green][y][1] == 0)
						{
							upCCW();
							solutions[*solutionIndex] = UPa;

							*solutionIndex += 1;
							switch (color - 48)
							{
								// DL
							case 1:
								frontCCW();
								leftCW();
								frontCW();

								solutions[*solutionIndex] = FRONTa;
								solutions[*solutionIndex + 1] = LEFT;
								solutions[*solutionIndex + 2] = FRONT;

								*solutionIndex += 3;
								break;
								// DF
							case 2:
								rightCCW();
								frontCW();
								rightCW();

								solutions[*solutionIndex] = RIGHTa;
								solutions[*solutionIndex + 1] = FRONT;
								solutions[*solutionIndex + 2] = RIGHT;

								*solutionIndex += 3;
								break;
								// DR
							case 3:
								backCCW();
								rightCW();
								backCW();

								solutions[*solutionIndex] = BACKa;
								solutions[*solutionIndex + 1] = RIGHT;
								solutions[*solutionIndex + 2] = BACK;

								*solutionIndex += 3;
								break;
								// DB
							case 4:
								leftCCW();
								backCW();
								leftCW();

								solutions[*solutionIndex] = LEFTa;
								solutions[*solutionIndex + 1] = BACK;
								solutions[*solutionIndex + 2] = LEFT;

								*solutionIndex += 3;
								break;
							}
						}
						// move green-square to top
						else
						{
							switch (color - 48)
							{
								// DL
							case 1:
								leftCW();
								leftCW();

								solutions[*solutionIndex] = LEFT;
								solutions[*solutionIndex + 1] = LEFT;

								*solutionIndex = *solutionIndex + 2;
								// restart for loop
								y = 12;
								break;
								// DF
							case 2:
								frontCW();
								frontCW();

								solutions[*solutionIndex] = FRONT;
								solutions[*solutionIndex + 1] = FRONT;

								*solutionIndex = *solutionIndex + 2;
								// restart for loop
								y = 12;
								break;
								// DR
							case 3:
								rightCW();
								rightCW();

								solutions[*solutionIndex] = RIGHT;
								solutions[*solutionIndex + 1] = RIGHT;

								*solutionIndex = *solutionIndex + 2;
								// restart for loop
								y = 12;
								break;
								// DB
							case 4:
								backCW();
								backCW();

								solutions[*solutionIndex] = BACK;
								solutions[*solutionIndex + 1] = BACK;

								*solutionIndex = *solutionIndex + 2;
								// restart for loop
								y = 12;
								break;
							}
						}
						break;
						// turn squares with index 4 - 12 to top layer and start over again
						// LB
					case 4:
						leftCW();
						upCW();
						leftCCW();

						solutions[*solutionIndex] = LEFT;
						solutions[*solutionIndex + 1] = UP;
						solutions[*solutionIndex + 2] = LEFTa;

						*solutionIndex += 3;
						// restart for loop
						y = 12;
						break;
						// RB
					case 5:
						rightCCW();
						upCW();
						rightCW();

						solutions[*solutionIndex] = RIGHTa;
						solutions[*solutionIndex + 1] = UP;
						solutions[*solutionIndex + 2] = RIGHT;

						*solutionIndex += 3;
						// restart for loop
						y = 12;
						break;
						// LF
					case 6:
						leftCCW();
						upCW();
						leftCW();

						solutions[*solutionIndex] = LEFTa;
						solutions[*solutionIndex + 1] = UP;
						solutions[*solutionIndex + 2] = LEFT;

						*solutionIndex += 3;
						// restart for loop
						y = 12;
						break;
						// RF
					case 7:
						rightCW();
						upCW();
						rightCCW();

						solutions[*solutionIndex] = RIGHT;
						solutions[*solutionIndex + 1] = UP;
						solutions[*solutionIndex + 2] = RIGHTa;

						*solutionIndex += 3;
						// restart for loop
						y = 12;
						break;
						// DB
					case 8:
						if (DB != 1)
						{
							backCW();
							backCW();

							solutions[*solutionIndex] = BACK;
							solutions[*solutionIndex + 1] = BACK;

							*solutionIndex += 2;
							// restart for loop
							y = 12;
						}
						break;
						// DR
					case 9:
						if (DR != 1)
						{
							rightCW();
							rightCW();

							solutions[*solutionIndex] = RIGHT;
							solutions[*solutionIndex + 1] = RIGHT;

							*solutionIndex += 2;
							// restart for loop
							y = 12;
						}
						break;
						// DF
					case 10:
						if (DF != 1)
						{
							frontCW();
							frontCW();

							solutions[*solutionIndex] = FRONT;
							solutions[*solutionIndex + 1] = FRONT;

							*solutionIndex += 2;
							// restart for loop
							y = 12;
						}
						break;
						// DL
					case 11:
						if (DL != 1)
						{
							leftCW();
							leftCW();

							solutions[*solutionIndex] = LEFT;
							solutions[*solutionIndex + 1] = LEFT;

							*solutionIndex = *solutionIndex + 2;
							// restart for loop
							y = 12;
						}
						break;
					}
				}
			}
		}
	}
}

void Algoritme::firstLayerAlgorithm()
{
	// variables to check if corner squares are solved
	uint8_t DLB = 0; // square DownLeftBack
	uint8_t DRB = 0; // square DownRightBack
	uint8_t DLF = 0; // square DownLeftFront
	uint8_t DRF = 0; // square DownRightFront

	while (DLB != 1 || DRB != 1 || DLF != 1 || DRF != 1)
	{
		// check if bottom layer is already solved
		if (colourMap[6][5] == GREEN && colourMap[6][1] == ORANGE && colourMap[8][4] == YELLOW)
			DLB = 1;
		else
			DLB = 0;

		if (colourMap[8][5] == GREEN && colourMap[8][3] == RED && colourMap[6][4] == YELLOW)
			DRB = 1;
		else
			DRB = 0;

		if (colourMap[0][5] == GREEN && colourMap[8][1] == ORANGE && colourMap[6][2] == WHITE)
			DLF = 1;
		else
			DLF = 0;

		if (colourMap[2][5] == GREEN && colourMap[6][3] == RED && colourMap[8][2] == WHITE)
			DRF = 1;
		else
			DRF = 0;

		// if not all bottom layer items are solved, solve them
		if (DLB != 1 || DRB != 1 || DLF != 1 || DRF != 1)
		{
			// check corner pieces on green square
			int y;
			int green;
			char differentColor1;
			char differentColor2;
			for (y = 12; y < 20; y++)
			{
				// if one of the squares is green and bottom layer is not solved, move cube
				if ((colourMap[cubieMap[0][y][0]][cubieMap[0][y][1]] == GREEN || colourMap[cubieMap[1][y][0]][cubieMap[1][y][1]] == GREEN || colourMap[cubieMap[2][y][0]][cubieMap[2][y][1]] == GREEN) && (DLB != 1 || DRB != 1 || DLF != 1 || DRF != 1))
				{
					// if piece with a green square is on top, move it to bottom
					if (cubieMap[0][y][1] == 0)
					{
						// check which square of the piece is green;
						// green on top
						if (colourMap[cubieMap[0][y][0]][cubieMap[0][y][1]] == GREEN)
						{
							green = 0;
							differentColor1 = colourMap[cubieMap[1][y][0]][cubieMap[1][y][1]];
							differentColor2 = colourMap[cubieMap[2][y][0]][cubieMap[2][y][1]];
						}
						// green on right or left
						else if (colourMap[cubieMap[1][y][0]][cubieMap[1][y][1]] == GREEN)
						{
							green = 1;
							differentColor1 = colourMap[cubieMap[0][y][0]][cubieMap[0][y][1]];
							differentColor2 = colourMap[cubieMap[2][y][0]][cubieMap[2][y][1]];
						}
						// green on front or back
						else
						{
							green = 2;
							differentColor1 = colourMap[cubieMap[0][y][0]][cubieMap[0][y][1]];
							differentColor2 = colourMap[cubieMap[1][y][0]][cubieMap[1][y][1]];
						}

						int yValue1 = cubieMap[1][y][1];
						int yValue2 = cubieMap[2][y][1];
						int color1 = differentColor1 - '0';
						int color2 = differentColor2 - '0';

						while (!((yValue1 == color1 && yValue2 == color2) || (yValue1 == color2 && yValue2 == color1)))
						{
							upCCW();
							solutions[*solutionIndex] = UPa;
							*solutionIndex += 1;
							if (yValue1 < 4)
								yValue1 += 1;
							else
								yValue1 = 1;

							if (yValue2 < 4)
								yValue2 += 1;
							else
								yValue2 = 1;
						}
						// different colors are yellow and orange
						if ((differentColor1 == YELLOW && differentColor2 == ORANGE) || (differentColor1 == ORANGE && differentColor2 == YELLOW))
						{
							// top color is green
							if (green == 0)
							{
								leftCW();
								upCCW();
								leftCCW();
								upCW();
								backCCW();
								upCW();
								backCW();

								solutions[*solutionIndex] = LEFT;
								solutions[*solutionIndex + 1] = UPa;
								solutions[*solutionIndex + 2] = LEFTa;
								solutions[*solutionIndex + 3] = UP;
								solutions[*solutionIndex + 4] = BACKa;
								solutions[*solutionIndex + 5] = UP;
								solutions[*solutionIndex + 6] = BACK;

								*solutionIndex += 7;
							}
							// top color is orange
							else if (differentColor1 == ORANGE)
							{
								leftCW();
								upCW();
								leftCCW();

								solutions[*solutionIndex] = LEFT;
								solutions[*solutionIndex + 1] = UP;
								solutions[*solutionIndex + 2] = LEFTa;

								*solutionIndex += 3;
							}
							// top color is yellow
							else
							{
								upCW();
								leftCW();
								upCCW();
								leftCCW();

								solutions[*solutionIndex] = UP;
								solutions[*solutionIndex + 1] = LEFT;
								solutions[*solutionIndex + 2] = UPa;
								solutions[*solutionIndex + 3] = LEFTa;

								*solutionIndex += 4;
							}
						}
						// different colors are yellow and red
						else if ((differentColor1 == YELLOW && differentColor2 == RED) || (differentColor1 == RED && differentColor2 == YELLOW))
						{
							// top color is green
							if (green == 0)
							{
								rightCCW();
								upCW();
								rightCW();
								upCCW();
								backCW();
								upCCW();
								backCCW();

								solutions[*solutionIndex] = RIGHTa;
								solutions[*solutionIndex + 1] = UP;
								solutions[*solutionIndex + 2] = RIGHT;
								solutions[*solutionIndex + 3] = UPa;
								solutions[*solutionIndex + 4] = BACK;
								solutions[*solutionIndex + 5] = UPa;
								solutions[*solutionIndex + 6] = BACKa;

								*solutionIndex += 7;
							}
							// top color is red
							else if (differentColor1 == RED)
							{
								upCW();
								backCW();
								upCCW();
								backCCW();

								solutions[*solutionIndex] = UP;
								solutions[*solutionIndex + 1] = BACK;
								solutions[*solutionIndex + 2] = UPa;
								solutions[*solutionIndex + 3] = BACKa;

								*solutionIndex += 4;
							}
							// top color is yellow
							else
							{
								upCCW();
								rightCCW();
								upCW();
								rightCW();

								solutions[*solutionIndex] = UPa;
								solutions[*solutionIndex + 1] = RIGHTa;
								solutions[*solutionIndex + 2] = UP;
								solutions[*solutionIndex + 3] = RIGHT;

								*solutionIndex += 4;
							}
						}
						// different colors are white and red
						else if ((differentColor1 == WHITE && differentColor2 == RED) || (differentColor1 == RED && differentColor2 == WHITE))
						{
							// top color is green
							if (green == 0)
							{
								rightCW();
								upCCW();
								rightCCW();
								upCW();
								frontCCW();
								upCW();
								frontCW();

								solutions[*solutionIndex] = RIGHT;
								solutions[*solutionIndex + 1] = UPa;
								solutions[*solutionIndex + 2] = RIGHTa;
								solutions[*solutionIndex + 3] = UP;
								solutions[*solutionIndex + 4] = FRONTa;
								solutions[*solutionIndex + 5] = UP;
								solutions[*solutionIndex + 6] = FRONT;

								*solutionIndex += 7;
							}
							// top color is red
							else if (differentColor1 == RED)
							{
								upCCW();
								frontCCW();
								upCW();
								frontCW();

								solutions[*solutionIndex] = UPa;
								solutions[*solutionIndex + 1] = FRONTa;
								solutions[*solutionIndex + 2] = UP;
								solutions[*solutionIndex + 3] = FRONT;

								*solutionIndex += 4;
							}
							// top color is white
							else
							{
								upCW();
								rightCW();
								upCCW();
								rightCCW();

								solutions[*solutionIndex] = UP;
								solutions[*solutionIndex + 1] = RIGHT;
								solutions[*solutionIndex + 2] = UPa;
								solutions[*solutionIndex + 3] = RIGHTa;

								*solutionIndex += 4;
							}
							DRF = 1;
						}
						// different colors are white and orange
						else
						{
							// top color is green
							if (green == 0)
							{
								leftCCW();
								upCW();
								leftCW();
								upCW();
								upCW();
								leftCCW();
								upCCW();
								leftCW();

								solutions[*solutionIndex] = LEFTa;
								solutions[*solutionIndex + 1] = UP;
								solutions[*solutionIndex + 2] = LEFT;
								solutions[*solutionIndex + 3] = UP;
								solutions[*solutionIndex + 4] = UP;
								solutions[*solutionIndex + 5] = LEFTa;
								solutions[*solutionIndex + 6] = UPa;
								solutions[*solutionIndex + 7] = LEFT;

								*solutionIndex += 8;
							}
							// top color is white
							else if (differentColor1 == WHITE)
							{
								upCCW();
								leftCCW();
								upCW();
								leftCW();

								solutions[*solutionIndex] = UPa;
								solutions[*solutionIndex + 1] = LEFTa;
								solutions[*solutionIndex + 2] = UP;
								solutions[*solutionIndex + 3] = LEFT;

								*solutionIndex += 4;
							}
							// top color is orange
							else
							{
								upCW();
								frontCW();
								upCCW();
								frontCCW();

								solutions[*solutionIndex] = UP;
								solutions[*solutionIndex + 1] = FRONT;
								solutions[*solutionIndex + 2] = UPa;
								solutions[*solutionIndex + 3] = FRONTa;

								*solutionIndex += 4;
							}

						}
						// reset for loop
						y = 19;
					}
					// if piece with a green square is on bottom, move it to top and restart for loop
					else
					{
						switch (y)
						{
							// DLB
						case 16:
							if (DLB != 1)
							{
								leftCW();
								upCW();
								leftCCW();

								solutions[*solutionIndex] = LEFT;
								solutions[*solutionIndex + 1] = UP;
								solutions[*solutionIndex + 2] = LEFTa;

								*solutionIndex += 3;
								y = 19;
							}
							break;
							// DRB
						case 17:
							if (DRB != 1)
							{
								rightCCW();
								upCW();
								rightCW();

								solutions[*solutionIndex] = RIGHTa;
								solutions[*solutionIndex + 1] = UP;
								solutions[*solutionIndex + 2] = RIGHT;

								*solutionIndex += 3;
								y = 19;
							}
							break;
							// DLF
						case 18:
							if (DLF != 1)
							{
								leftCCW();
								upCW();
								leftCW();

								solutions[*solutionIndex] = LEFTa;
								solutions[*solutionIndex + 1] = UP;
								solutions[*solutionIndex + 2] = LEFT;

								*solutionIndex += 3;
								y = 19;
							}
							break;
							// DRF
						case 19:
							if (DRF != 1)
							{
								rightCW();
								upCW();
								rightCCW();

								solutions[*solutionIndex] = RIGHT;
								solutions[*solutionIndex + 1] = UP;
								solutions[*solutionIndex + 2] = RIGHTa;

								*solutionIndex += 3;
								y = 19;
							}
							break;
						}
					}
				}
			}
		}
	}
}

void Algoritme::secondLayerAlgorithm()
{
	// variables to check if cross items are solved
	uint8_t LB = 0; // square LeftBack
	uint8_t RB = 0; // square RightBack
	uint8_t LF = 0; // square LeftFront
	uint8_t RF = 0; // square RightFront

	while (LB != 1 || RB != 1 || LF != 1 || RF != 1)
	{
		// check if second layer is already solved
		if (colourMap[3][1] == ORANGE && colourMap[5][4] == YELLOW)
			LB = 1;
		else
			LB = 0;

		if (colourMap[5][3] == RED && colourMap[3][4] == YELLOW)
			RB = 1;
		else
			RB = 0;

		if (colourMap[5][1] == ORANGE && colourMap[3][2] == WHITE)
			LF = 1;
		else
			LF = 0;

		if (colourMap[3][3] == RED && colourMap[5][2] == WHITE)
			RF = 1;
		else
			RF = 0;

		// if not all second layer items are solved, solve them
		if (LB != 1 || RB != 1 || LF != 1 || RF != 1)
		{
			// check edge pieces of second layer
			int y;
			char color;
			for (y = 0; y < 8; y++)
			{
				// if one of the squares is not blue and second layer is not solved, move cube
				if (!(colourMap[cubieMap[0][y][0]][cubieMap[0][y][1]] == BLUE || colourMap[cubieMap[1][y][0]][cubieMap[1][y][1]] == BLUE) && (LB != 1 || RB != 1 || LF != 1 || RF != 1))
				{
					color = colourMap[cubieMap[1][y][0]][cubieMap[1][y][1]];
					int yValue = cubieMap[1][y][1];
					int xValue = color - '0';
					switch (y)
					{
						// square is on top of cube
					case 0:
					case 1:
					case 2:
					case 3:
						while (xValue != yValue) {
							upCCW();
							solutions[*solutionIndex] = UPa;
							*solutionIndex += 1;
							if (yValue < 4)
								yValue += 1;
							else
								yValue = 1;
						}
						// color is yellow and orange
						if ((color == YELLOW && colourMap[cubieMap[0][y][0]][cubieMap[0][y][1]] == ORANGE) || (color == ORANGE && colourMap[cubieMap[0][y][0]][cubieMap[0][y][1]] == YELLOW))
						{
							// top color is yellow
							if (color == ORANGE)
							{
								upCCW();
								backCCW();
								upCW();
								backCW();
								upCW();
								leftCW();
								upCCW();
								leftCCW();

								solutions[*solutionIndex] = UPa;
								solutions[*solutionIndex + 1] = BACKa;
								solutions[*solutionIndex + 2] = UP;
								solutions[*solutionIndex + 3] = BACK;
								solutions[*solutionIndex + 4] = UP;
								solutions[*solutionIndex + 5] = LEFT;
								solutions[*solutionIndex + 6] = UPa;
								solutions[*solutionIndex + 7] = LEFTa;

								*solutionIndex += 8;
								// restart for loop
								y = 8;
							}
							// top color is orange
							else
							{
								upCW();
								leftCW();
								upCCW();
								leftCCW();
								upCCW();
								backCCW();
								upCW();
								backCW();

								solutions[*solutionIndex] = UP;
								solutions[*solutionIndex + 1] = LEFT;
								solutions[*solutionIndex + 2] = UPa;
								solutions[*solutionIndex + 3] = LEFTa;
								solutions[*solutionIndex + 4] = UPa;
								solutions[*solutionIndex + 5] = BACKa;
								solutions[*solutionIndex + 6] = UP;
								solutions[*solutionIndex + 7] = BACK;

								*solutionIndex += 8;
								// restart for loop
								y = 8;
							}
						}
						// color is yellow and red
						else if ((color == YELLOW && colourMap[cubieMap[0][y][0]][cubieMap[0][y][1]] == RED) || (color == RED && colourMap[cubieMap[0][y][0]][cubieMap[0][y][1]] == YELLOW))
						{
							// top color is yellow
							if (color == RED)
							{
								upCW();
								backCW();
								upCCW();
								backCCW();
								upCCW();
								rightCCW();
								upCW();
								rightCW();

								solutions[*solutionIndex] = UP;
								solutions[*solutionIndex + 1] = BACK;
								solutions[*solutionIndex + 2] = UPa;
								solutions[*solutionIndex + 3] = BACKa;
								solutions[*solutionIndex + 4] = UPa;
								solutions[*solutionIndex + 5] = RIGHTa;
								solutions[*solutionIndex + 6] = UP;
								solutions[*solutionIndex + 7] = RIGHT;

								*solutionIndex += 8;
								// restart for loop
								y = 8;
							}
							// top color is red
							else
							{
								upCCW();
								rightCCW();
								upCW();
								rightCW();
								upCW();
								backCW();
								upCCW();
								backCCW();

								solutions[*solutionIndex] = UPa;
								solutions[*solutionIndex + 1] = RIGHTa;
								solutions[*solutionIndex + 2] = UP;
								solutions[*solutionIndex + 3] = RIGHT;
								solutions[*solutionIndex + 4] = UP;
								solutions[*solutionIndex + 5] = BACK;
								solutions[*solutionIndex + 6] = UPa;
								solutions[*solutionIndex + 7] = BACKa;

								*solutionIndex += 8;
								// restart for loop
								y = 8;
							}
						}
						// color is white and red
						else if ((color == WHITE && colourMap[cubieMap[0][y][0]][cubieMap[0][y][1]] == RED) || (color == RED && colourMap[cubieMap[0][y][0]][cubieMap[0][y][1]] == WHITE))
						{
							// top color is red
							if (color == WHITE)
							{
								upCW();
								rightCW();
								upCCW();
								rightCCW();
								upCCW();
								frontCCW();
								upCW();
								frontCW();

								solutions[*solutionIndex] = UP;
								solutions[*solutionIndex + 1] = RIGHT;
								solutions[*solutionIndex + 2] = UPa;
								solutions[*solutionIndex + 3] = RIGHTa;
								solutions[*solutionIndex + 4] = UPa;
								solutions[*solutionIndex + 5] = FRONTa;
								solutions[*solutionIndex + 6] = UP;
								solutions[*solutionIndex + 7] = FRONT;

								*solutionIndex += 8;
								// restart for loop
								y = 8;
							}
							// top color is white
							else
							{
								upCCW();
								frontCCW();
								upCW();
								frontCW();
								upCW();
								rightCW();
								upCCW();
								rightCCW();

								solutions[*solutionIndex] = UPa;
								solutions[*solutionIndex + 1] = FRONTa;
								solutions[*solutionIndex + 2] = UP;
								solutions[*solutionIndex + 3] = FRONT;
								solutions[*solutionIndex + 4] = UP;
								solutions[*solutionIndex + 5] = RIGHT;
								solutions[*solutionIndex + 6] = UPa;
								solutions[*solutionIndex + 7] = RIGHTa;

								*solutionIndex += 8;
								// restart for loop
								y = 8;
							}
						}
						// color is white and orange
						else if ((color == WHITE && colourMap[cubieMap[0][y][0]][cubieMap[0][y][1]] == ORANGE) || (color == ORANGE && colourMap[cubieMap[0][y][0]][cubieMap[0][y][1]] == WHITE))
						{
							// top color is orange
							if (color == WHITE)
							{
								upCCW();
								leftCCW();
								upCW();
								leftCW();
								upCW();
								frontCW();
								upCCW();
								frontCCW();

								solutions[*solutionIndex] = UPa;
								solutions[*solutionIndex + 1] = LEFTa;
								solutions[*solutionIndex + 2] = UP;
								solutions[*solutionIndex + 3] = LEFT;
								solutions[*solutionIndex + 4] = UP;
								solutions[*solutionIndex + 5] = FRONT;
								solutions[*solutionIndex + 6] = UPa;
								solutions[*solutionIndex + 7] = FRONTa;

								*solutionIndex += 8;
								// restart for loop
								y = 8;
							}
							// top color is white
							else
							{
								upCW();
								frontCW();
								upCCW();
								frontCCW();
								upCCW();
								leftCCW();
								upCW();
								leftCW();

								solutions[*solutionIndex] = UP;
								solutions[*solutionIndex + 1] = FRONT;
								solutions[*solutionIndex + 2] = UPa;
								solutions[*solutionIndex + 3] = FRONTa;
								solutions[*solutionIndex + 4] = UPa;
								solutions[*solutionIndex + 5] = LEFTa;
								solutions[*solutionIndex + 6] = UP;
								solutions[*solutionIndex + 7] = LEFT;

								*solutionIndex += 8;
								// restart for loop
								y = 8;
							}
						}
						break;
						// square is not on top of cube and is not solved yet
						// LB
					case 4:
						if (!(colourMap[3][1] == ORANGE && colourMap[5][4] == YELLOW))
						{
							leftCW();
							upCCW();
							leftCCW();
							upCCW();
							backCCW();
							upCW();
							backCW();

							solutions[*solutionIndex] = LEFT;
							solutions[*solutionIndex + 1] = UPa;
							solutions[*solutionIndex + 2] = LEFTa;
							solutions[*solutionIndex + 3] = UPa;
							solutions[*solutionIndex + 4] = BACKa;
							solutions[*solutionIndex + 5] = UP;
							solutions[*solutionIndex + 6] = BACK;

							*solutionIndex += 7;
							// restart for loop
							y = 8;
						}
						break;
						// RB
					case 5:
						if (!(colourMap[5][3] == RED && colourMap[3][4] == YELLOW))
						{
							backCW();
							upCCW();
							backCCW();
							upCCW();
							rightCCW();
							upCW();
							rightCW();

							solutions[*solutionIndex] = BACK;
							solutions[*solutionIndex + 1] = UPa;
							solutions[*solutionIndex + 2] = BACKa;
							solutions[*solutionIndex + 3] = UPa;
							solutions[*solutionIndex + 4] = RIGHTa;
							solutions[*solutionIndex + 5] = UP;
							solutions[*solutionIndex + 6] = RIGHT;

							*solutionIndex += 7;
							// restart for loop
							y = 8;
						}
						break;
						// LF
					case 6:
						if (!(colourMap[5][1] == ORANGE && colourMap[3][2] == WHITE))
						{
							leftCCW();
							upCW();
							leftCW();
							upCW();
							frontCW();
							upCCW();
							frontCCW();

							solutions[*solutionIndex] = LEFTa;
							solutions[*solutionIndex + 1] = UP;
							solutions[*solutionIndex + 2] = LEFT;
							solutions[*solutionIndex + 3] = UP;
							solutions[*solutionIndex + 4] = FRONT;
							solutions[*solutionIndex + 5] = UPa;
							solutions[*solutionIndex + 6] = FRONTa;

							*solutionIndex += 7;
							// restart for loop
							y = 8;
						}
						break;
						// RF
					case 7:
						if (!(colourMap[3][3] == RED && colourMap[5][2] == WHITE))
						{
							rightCW();
							upCCW();
							rightCCW();
							upCCW();
							frontCCW();
							upCW();
							frontCW();

							solutions[*solutionIndex] = RIGHT;
							solutions[*solutionIndex + 1] = UPa;
							solutions[*solutionIndex + 2] = RIGHTa;
							solutions[*solutionIndex + 3] = UPa;
							solutions[*solutionIndex + 4] = FRONTa;
							solutions[*solutionIndex + 5] = UP;
							solutions[*solutionIndex + 6] = FRONT;

							*solutionIndex += 7;
							// restart for loop
							y = 8;
						}
						break;
					}
				}
			}
		}
	}
}

void Algoritme::upCrossAlgorithm()
{
	// variables to check if cross items are solved
	uint8_t UB = 0; // square UpBack
	uint8_t UR = 0; // square UpRight
	uint8_t UF = 0; // square UpFront
	uint8_t UL = 0; // square UpLeft

	while (UB != 1 || UR != 1 || UF != 1 || UL != 1)
	{
		// check if cross is already solved
		if (colourMap[1][0] == BLUE)
			UB = 1;
		else
			UB = 0;

		if (colourMap[5][0] == BLUE)
			UR = 1;
		else
			UR = 0;

		if (colourMap[7][0] == BLUE)
			UF = 1;
		else
			UF = 0;

		if (colourMap[3][0] == BLUE)
			UL = 1;
		else
			UL = 0;

		// if not all cross items are solved, solve them
		if (UB != 1 || UR != 1 || UF != 1 || UL != 1)
		{
			// U2 and U4
			if (colourMap[1][0] == BLUE && colourMap[3][0] == BLUE)
			{
				frontCW();
				upCW();
				rightCW();
				upCCW();
				rightCCW();
				frontCCW();

				solutions[*solutionIndex] = FRONT;
				solutions[*solutionIndex + 1] = UP;
				solutions[*solutionIndex + 2] = RIGHT;
				solutions[*solutionIndex + 3] = UPa;
				solutions[*solutionIndex + 4] = RIGHTa;
				solutions[*solutionIndex + 5] = FRONTa;

				*solutionIndex += 6;
			}
			// U2 and U6
			else if (colourMap[1][0] == BLUE && colourMap[5][0] == BLUE)
			{
				upCCW();
				frontCW();
				upCW();
				rightCW();
				upCCW();
				rightCCW();
				frontCCW();

				solutions[*solutionIndex] = UPa;
				solutions[*solutionIndex + 1] = FRONT;
				solutions[*solutionIndex + 2] = UP;
				solutions[*solutionIndex + 3] = RIGHT;
				solutions[*solutionIndex + 4] = UPa;
				solutions[*solutionIndex + 5] = RIGHTa;
				solutions[*solutionIndex + 6] = FRONTa;

				*solutionIndex += 7;
			}
			// U6 and U8
			else if (colourMap[5][0] == BLUE && colourMap[7][0] == BLUE)
			{
				upCW();
				upCW();
				frontCW();
				upCW();
				rightCW();
				upCCW();
				rightCCW();
				frontCCW();

				solutions[*solutionIndex] = UP;
				solutions[*solutionIndex + 1] = UP;
				solutions[*solutionIndex + 2] = FRONT;
				solutions[*solutionIndex + 3] = UP;
				solutions[*solutionIndex + 4] = RIGHT;
				solutions[*solutionIndex + 5] = UPa;
				solutions[*solutionIndex + 6] = RIGHTa;
				solutions[*solutionIndex + 7] = FRONTa;

				*solutionIndex += 8;
			}
			// U8 and U4
			else if (colourMap[7][0] == BLUE && colourMap[3][0] == BLUE)
			{
				upCW();
				frontCW();
				upCW();
				rightCW();
				upCCW();
				rightCCW();
				frontCCW();

				solutions[*solutionIndex] = UP;
				solutions[*solutionIndex + 1] = FRONT;
				solutions[*solutionIndex + 2] = UP;
				solutions[*solutionIndex + 3] = RIGHT;
				solutions[*solutionIndex + 4] = UPa;
				solutions[*solutionIndex + 5] = RIGHTa;
				solutions[*solutionIndex + 6] = FRONTa;

				*solutionIndex += 7;
			}
			// U4 and U6
			else if (colourMap[3][0] == BLUE && colourMap[5][0] == BLUE)
			{
				frontCW();
				rightCW();
				upCW();
				rightCCW();
				upCCW();
				frontCCW();

				solutions[*solutionIndex] = FRONT;
				solutions[*solutionIndex + 1] = RIGHT;
				solutions[*solutionIndex + 2] = UP;
				solutions[*solutionIndex + 3] = RIGHTa;
				solutions[*solutionIndex + 4] = UPa;
				solutions[*solutionIndex + 5] = FRONTa;

				*solutionIndex += 6;
			}
			// U8 and U4
			else if (colourMap[7][0] == BLUE && colourMap[3][0] == BLUE)
			{
				upCW();
				upCW();
				frontCW();
				rightCW();
				upCW();
				rightCCW();
				upCCW();
				frontCCW();

				solutions[*solutionIndex] = UP;
				solutions[*solutionIndex + 1] = UP;
				solutions[*solutionIndex + 2] = FRONT;
				solutions[*solutionIndex + 3] = RIGHT;
				solutions[*solutionIndex + 4] = UP;
				solutions[*solutionIndex + 5] = RIGHTa;
				solutions[*solutionIndex + 6] = UPa;
				solutions[*solutionIndex + 7] = FRONTa;

				*solutionIndex += 8;
			}
			// nothing on top
			else
			{
				frontCW();
				upCW();
				rightCW();
				upCCW();
				rightCCW();
				frontCCW();

				solutions[*solutionIndex] = FRONT;
				solutions[*solutionIndex + 1] = UP;
				solutions[*solutionIndex + 2] = RIGHT;
				solutions[*solutionIndex + 3] = UPa;
				solutions[*solutionIndex + 4] = RIGHTa;
				solutions[*solutionIndex + 5] = FRONTa;

				*solutionIndex += 6;
			}
		}
	}
}

void Algoritme::thirdLayerAlgorithm()
{
	// variables to check if top-layer items are solved
	uint8_t ULB = 0; // square UpLeftBack
	uint8_t URB = 0; // square UpRightBack
	uint8_t ULF = 0; // square UpLeftFront
	uint8_t URF = 0; // square UpRightFront

	while (ULB != 1 || URB != 1 || ULF != 1 || URF != 1)
	{
		// check if top-layer is already solved
		uint8_t amountBluePieces = 0;
		if (colourMap[0][0] == BLUE)
		{
			ULB = 1;
			amountBluePieces++;
		}
		else
			ULB = 0;

		if (colourMap[2][0] == BLUE)
		{
			URB = 1;
			amountBluePieces++;
		}
		else
			URB = 0;

		if (colourMap[6][0] == BLUE)
		{
			ULF = 1;
			amountBluePieces++;
		}
		else
			ULF = 0;

		if (colourMap[8][0] == BLUE)
		{
			URF = 1;
			amountBluePieces++;
		}
		else
			URF = 0;

		// if not all top-layer items are solved, solve them
		if (ULB != 1 || URB != 1 || ULF != 1 || URF != 1)
		{
			switch (amountBluePieces)
			{
				// check if 1 top-layer piece is blue
			case 1:
				// check if blue piece is on U7, else turn it to U7
				while (!(colourMap[6][0] == BLUE))
				{
					upCW();
					solutions[*solutionIndex] = UP;
					*solutionIndex += 1;
				}
				break;
				// check if 2 top-layer pieces are blue
			case 2:
				// check if F1 is blue, else turn it till its blue
				while (!(colourMap[0][2] == BLUE))
				{
					upCW();
					solutions[*solutionIndex] = UP;
					*solutionIndex += 1;
				}
				break;
			}
			rightCW();
			upCW();
			rightCCW();
			upCW();
			rightCW();
			upCW();
			upCW();
			rightCCW();

			solutions[*solutionIndex] = RIGHT;
			solutions[*solutionIndex + 1] = UP;
			solutions[*solutionIndex + 2] = RIGHTa;
			solutions[*solutionIndex + 3] = UP;
			solutions[*solutionIndex + 4] = RIGHT;
			solutions[*solutionIndex + 5] = UP;
			solutions[*solutionIndex + 6] = UP;
			solutions[*solutionIndex + 7] = RIGHTa;

			*solutionIndex += 8;
		}
	}
}

void Algoritme::upCornerAlgorithm()
{
	// variables to check if top-corner items are solved
	uint8_t ULB = 0; // square UpLeftBack
	uint8_t URB = 0; // square UpRightBack
	uint8_t ULF = 0; // square UpLeftFront
	uint8_t URF = 0; // square UpRightFront

	while (ULB != 1 || URB != 1 || ULF != 1 || URF != 1)
	{
		// check if top-corners are already solved
		if (colourMap[0][0] == BLUE && colourMap[0][1] == ORANGE && colourMap[2][4] == YELLOW)
			ULB = 1;
		else
			ULB = 0;

		if (colourMap[2][0] == BLUE && colourMap[2][3] == RED && colourMap[0][4] == YELLOW)
			URB = 1;
		else
			URB = 0;

		if (colourMap[6][0] == BLUE && colourMap[2][1] == ORANGE && colourMap[0][2] == WHITE)
			ULF = 1;
		else
			ULF = 0;

		if (colourMap[8][0] == BLUE && colourMap[0][3] == RED && colourMap[2][2] == WHITE)
			URF = 1;
		else
			URF = 0;

		// if not all top-corner items are solved, solve them
		if (ULB != 1 || URB != 1 || ULF != 1 || URF != 1)
		{
			// R1 and R3, F1 and F3, L1 and L3 and B1 and B3 are equal to eachother
			if (colourMap[0][3] == colourMap[2][3] && colourMap[0][2] == colourMap[2][2] && colourMap[0][1] == colourMap[2][1] && colourMap[0][4] == colourMap[2][4])
			{
				int color = colourMap[2][4] - '0';
				int yValue = 4;

				while (color != yValue) {
					upCCW();
					solutions[*solutionIndex] = UPa;
					*solutionIndex += 1;
					if (yValue < 4)
						yValue += 1;
					else
						yValue = 1;
				}
			}
			else
			{
				// R1 and R3 are equal to eachother
				if (colourMap[0][3] == colourMap[2][3])
				{
					upCCW();
					solutions[*solutionIndex] = UPa;
					*solutionIndex += 1;
				}
				// F1 and F3 are equal to eachother
				else if (colourMap[0][2] == colourMap[2][2])
				{
					upCW();
					upCW();

					solutions[*solutionIndex] = UP;
					solutions[*solutionIndex + 1] = UP;

					*solutionIndex += 2;
				}
				// L1 and L3 are equal to eachother
				else if (colourMap[0][1] == colourMap[2][1])
				{
					upCW();
					solutions[*solutionIndex] = UP;
					*solutionIndex += 1;
				}

				rightCCW();
				frontCW();
				rightCCW();
				backCW();
				backCW();
				rightCW();
				frontCCW();
				rightCCW();
				backCW();
				backCW();
				rightCW();
				rightCW();

				solutions[*solutionIndex] = RIGHTa;
				solutions[*solutionIndex + 1] = FRONT;
				solutions[*solutionIndex + 2] = RIGHTa;
				solutions[*solutionIndex + 3] = BACK;
				solutions[*solutionIndex + 4] = BACK;
				solutions[*solutionIndex + 5] = RIGHT;
				solutions[*solutionIndex + 6] = FRONTa;
				solutions[*solutionIndex + 7] = RIGHTa;
				solutions[*solutionIndex + 8] = BACK;
				solutions[*solutionIndex + 9] = BACK;
				solutions[*solutionIndex + 10] = RIGHT;
				solutions[*solutionIndex + 11] = RIGHT;

				*solutionIndex += 12;
			}
		}
	}
}

void Algoritme::upMiddleAlgorithm()
{
	// variables to check if top-middle items are solved
	uint8_t UB = 0; // square UpBack
	uint8_t UR = 0; // square UpRight
	uint8_t UF = 0; // square UpFront
	uint8_t UL = 0; // square UpLeft

	uint8_t loopProtection = 0; // variable to check if cube isn't in an infinite loop

	while (UB != 1 || UR != 1 || UF != 1 || UL != 1)
	{
		// check if top-middle items are already solved
		if (colourMap[1][0] == BLUE && colourMap[1][4] == YELLOW)
			UB = 1;
		else
			UB = 0;

		if (colourMap[5][0] == BLUE && colourMap[1][3] == RED)
			UR = 1;
		else
			UR = 0;

		if (colourMap[7][0] == BLUE && colourMap[1][2] == WHITE)
			UF = 1;
		else
			UF = 0;

		if (colourMap[3][0] == BLUE && colourMap[1][1] == ORANGE)
			UL = 1;
		else
			UL = 0;

		// if not all top-middle items are solved, solve them
		if (UB != 1 || UR != 1 || UF != 1 || UL != 1)
		{
			// check if red side is solved
			if (colourMap[0][3] == RED && colourMap[1][3] == RED && colourMap[2][3] == RED)
			{
				// if L2 is yellow
				if (colourMap[1][1] == YELLOW)
				{
					leftCW();
					leftCW();
					upCW();
					backCW();
					frontCCW();
					leftCW();
					leftCW();
					backCCW();
					frontCW();
					upCW();
					leftCW();
					leftCW();

					solutions[*solutionIndex] = LEFT;
					solutions[*solutionIndex + 1] = LEFT;
					solutions[*solutionIndex + 2] = UP;
					solutions[*solutionIndex + 3] = BACK;
					solutions[*solutionIndex + 4] = FRONTa;
					solutions[*solutionIndex + 5] = LEFT;
					solutions[*solutionIndex + 6] = LEFT;
					solutions[*solutionIndex + 7] = BACKa;
					solutions[*solutionIndex + 8] = FRONT;
					solutions[*solutionIndex + 9] = UP;
					solutions[*solutionIndex + 10] = LEFT;
					solutions[*solutionIndex + 11] = LEFT;

					*solutionIndex += 12;
				}
				// if L2 is white
				else
				{
					leftCW();
					leftCW();
					upCCW();
					backCW();
					frontCCW();
					leftCW();
					leftCW();
					backCCW();
					frontCW();
					upCCW();
					leftCW();
					leftCW();

					solutions[*solutionIndex] = LEFT;
					solutions[*solutionIndex + 1] = LEFT;
					solutions[*solutionIndex + 2] = UPa;
					solutions[*solutionIndex + 3] = BACK;
					solutions[*solutionIndex + 4] = FRONTa;
					solutions[*solutionIndex + 5] = LEFT;
					solutions[*solutionIndex + 6] = LEFT;
					solutions[*solutionIndex + 7] = BACKa;
					solutions[*solutionIndex + 8] = FRONT;
					solutions[*solutionIndex + 9] = UPa;
					solutions[*solutionIndex + 10] = LEFT;
					solutions[*solutionIndex + 11] = LEFT;

					*solutionIndex += 12;
				}
			}
			// check if white side is solved
			else if (colourMap[0][2] == WHITE && colourMap[1][2] == WHITE && colourMap[2][2] == WHITE)
			{
				// if B2 is red
				if (colourMap[1][4] == RED)
				{
					backCW();
					backCW();
					upCW();
					rightCW();
					leftCCW();
					backCW();
					backCW();
					rightCCW();
					leftCW();
					upCW();
					backCW();
					backCW();

					solutions[*solutionIndex] = BACK;
					solutions[*solutionIndex + 1] = BACK;
					solutions[*solutionIndex + 2] = UP;
					solutions[*solutionIndex + 3] = RIGHT;
					solutions[*solutionIndex + 4] = LEFTa;
					solutions[*solutionIndex + 5] = BACK;
					solutions[*solutionIndex + 6] = BACK;
					solutions[*solutionIndex + 7] = RIGHTa;
					solutions[*solutionIndex + 8] = LEFT;
					solutions[*solutionIndex + 9] = UP;
					solutions[*solutionIndex + 10] = BACK;
					solutions[*solutionIndex + 11] = BACK;

					*solutionIndex += 12;
				}
				// if B2 is orange
				else
				{
					backCW();
					backCW();
					upCCW();
					rightCW();
					leftCCW();
					backCW();
					backCW();
					rightCCW();
					leftCW();
					upCCW();
					backCW();
					backCW();

					solutions[*solutionIndex] = BACK;
					solutions[*solutionIndex + 1] = BACK;
					solutions[*solutionIndex + 2] = UPa;
					solutions[*solutionIndex + 3] = RIGHT;
					solutions[*solutionIndex + 4] = LEFTa;
					solutions[*solutionIndex + 5] = BACK;
					solutions[*solutionIndex + 6] = BACK;
					solutions[*solutionIndex + 7] = RIGHTa;
					solutions[*solutionIndex + 8] = LEFT;
					solutions[*solutionIndex + 9] = UPa;
					solutions[*solutionIndex + 10] = BACK;
					solutions[*solutionIndex + 11] = BACK;

					*solutionIndex += 12;
				}
			}
			// check if orange side is solved
			else if (colourMap[0][1] == ORANGE && colourMap[1][1] == ORANGE && colourMap[2][1] == ORANGE)
			{
				// if R2 is white
				if (colourMap[1][3] == WHITE)
				{
					rightCW();
					rightCW();
					upCW();
					frontCW();
					backCCW();
					rightCW();
					rightCW();
					frontCCW();
					backCW();
					upCW();
					rightCW();
					rightCW();

					solutions[*solutionIndex] = RIGHT;
					solutions[*solutionIndex + 1] = RIGHT;
					solutions[*solutionIndex + 2] = UP;
					solutions[*solutionIndex + 3] = FRONT;
					solutions[*solutionIndex + 4] = BACKa;
					solutions[*solutionIndex + 5] = RIGHT;
					solutions[*solutionIndex + 6] = RIGHT;
					solutions[*solutionIndex + 7] = FRONTa;
					solutions[*solutionIndex + 8] = BACK;
					solutions[*solutionIndex + 9] = UP;
					solutions[*solutionIndex + 10] = RIGHT;
					solutions[*solutionIndex + 11] = RIGHT;

					*solutionIndex += 12;
				}
				// if R2 is yellow
				else
				{
					rightCW();
					rightCW();
					upCCW();
					frontCW();
					backCCW();
					rightCW();
					rightCW();
					frontCCW();
					backCW();
					upCCW();
					rightCW();
					rightCW();

					solutions[*solutionIndex] = RIGHT;
					solutions[*solutionIndex + 1] = RIGHT;
					solutions[*solutionIndex + 2] = UPa;
					solutions[*solutionIndex + 3] = FRONT;
					solutions[*solutionIndex + 4] = BACKa;
					solutions[*solutionIndex + 5] = RIGHT;
					solutions[*solutionIndex + 6] = RIGHT;
					solutions[*solutionIndex + 7] = FRONTa;
					solutions[*solutionIndex + 8] = BACK;
					solutions[*solutionIndex + 9] = UPa;
					solutions[*solutionIndex + 10] = RIGHT;
					solutions[*solutionIndex + 11] = RIGHT;

					*solutionIndex += 12;
				}
			}
			// check if back side is solved
			else if (colourMap[0][4] == YELLOW && colourMap[1][4] == YELLOW && colourMap[2][4] == YELLOW)
			{
				// if F2 is orange
				if (colourMap[1][2] == ORANGE)
				{
					frontCW();
					frontCW();
					upCW();
					rightCCW();
					leftCW();
					frontCW();
					frontCW();
					rightCW();
					leftCCW();
					upCW();
					frontCW();
					frontCW();

					solutions[*solutionIndex] = FRONT;
					solutions[*solutionIndex + 1] = FRONT;
					solutions[*solutionIndex + 2] = UP;
					solutions[*solutionIndex + 3] = RIGHTa;
					solutions[*solutionIndex + 4] = LEFT;
					solutions[*solutionIndex + 5] = FRONT;
					solutions[*solutionIndex + 6] = FRONT;
					solutions[*solutionIndex + 7] = RIGHT;
					solutions[*solutionIndex + 8] = LEFTa;
					solutions[*solutionIndex + 9] = UP;
					solutions[*solutionIndex + 10] = FRONT;
					solutions[*solutionIndex + 11] = FRONT;

					*solutionIndex += 12;
				}
				// if F2 is red
				else
				{
					frontCW();
					frontCW();
					upCCW();
					rightCCW();
					leftCW();
					frontCW();
					frontCW();
					rightCW();
					leftCCW();
					upCCW();
					frontCW();
					frontCW();

					solutions[*solutionIndex] = FRONT;
					solutions[*solutionIndex + 1] = FRONT;
					solutions[*solutionIndex + 2] = UPa;
					solutions[*solutionIndex + 3] = RIGHTa;
					solutions[*solutionIndex + 4] = LEFT;
					solutions[*solutionIndex + 5] = FRONT;
					solutions[*solutionIndex + 6] = FRONT;
					solutions[*solutionIndex + 7] = RIGHT;
					solutions[*solutionIndex + 8] = LEFTa;
					solutions[*solutionIndex + 9] = UPa;
					solutions[*solutionIndex + 10] = FRONT;
					solutions[*solutionIndex + 11] = FRONT;
				}
			}
			else
			{
				// prevent program from loop
				if (loopProtection < 4)
				{
					loopProtection++;
					upCW();
					solutions[*solutionIndex] = UP;
					*solutionIndex += 1;
				}
				else
				{
					loopProtection = 0;
					frontCW();
					frontCW();
					upCW();
					rightCCW();
					leftCW();
					frontCW();
					frontCW();
					rightCW();
					leftCCW();
					upCW();
					frontCW();
					frontCW();

					solutions[*solutionIndex] = FRONT;
					solutions[*solutionIndex + 1] = FRONT;
					solutions[*solutionIndex + 2] = UP;
					solutions[*solutionIndex + 3] = RIGHTa;
					solutions[*solutionIndex + 4] = LEFT;
					solutions[*solutionIndex + 5] = FRONT;
					solutions[*solutionIndex + 6] = FRONT;
					solutions[*solutionIndex + 7] = RIGHT;
					solutions[*solutionIndex + 8] = LEFTa;
					solutions[*solutionIndex + 9] = UP;
					solutions[*solutionIndex + 10] = FRONT;
					solutions[*solutionIndex + 11] = FRONT;

					*solutionIndex += 12;
				}
			}
		}
	}
}
