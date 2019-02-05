#include "stdafx.h"
#include <stdint.h>

#ifndef ALGORITME_H
#define ALGORITME_H

// colours
#define BLUE '0'
#define ORANGE '1'
#define WHITE '2'
#define RED '3'
#define YELLOW '4'
#define GREEN '5'
#define UNKNOWN '6'

#define RIGHT 'R'
#define RIGHTa 'r'
#define LEFT 'L'
# define LEFTa 'l'
#define UP 'U'
#define UPa 'u'
#define DOWN 'D'
#define DOWNa 'd'
#define FRONT 'F'
#define FRONTa 'f'
#define BACK 'B'
#define BACKa 'b'
#define EMPTY 'E'

// map sizes
#define COLOUR_MAP_X 9
#define COLOUR_MAP_Y 7

#define CUBIE_MAP_X 3
#define CUBIE_MAP_Y 20

// amount of solutions in array
#define SOLUTION_AMOUNT 255


class Algoritme {
public:
	void run();
	char colourMap[COLOUR_MAP_X][COLOUR_MAP_Y];
	int cubieMap[CUBIE_MAP_X][CUBIE_MAP_Y][2];
	char solutions[SOLUTION_AMOUNT];
private:
	// initialization- and optimalization functions
	void init();
	void optimizeSolution();

	// functions to move cube in software, ClockWise and CounterClockWise
	void rightCW();
	void rightCCW();
	void leftCW();
	void leftCCW();
	void upCW();
	void upCCW();
	void downCW();
	void downCCW();
	void frontCW();
	void frontCCW();
	void backCW();
	void backCCW();

	// functions to solve cube
	void downCrossAlgorithm();
	void firstLayerAlgorithm();
	void secondLayerAlgorithm();
	void upCrossAlgorithm();
	void thirdLayerAlgorithm();
	void upCornerAlgorithm();
	void upMiddleAlgorithm();

	uint8_t* solutionIndex = new uint8_t;

	// test functions
	void printMap();
	void printCubieMap();
	void printArray();
	void printSolution();
};

#endif