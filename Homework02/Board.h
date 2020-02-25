#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <fstream>
#include "Cell.h"

using namespace std;

class Board
{
private:
	int dimension;
	Cell** board;
	Cell* initial;
	Cell* goal;
public:
	Board(string b);
	~Board();
	int getDimension();
	Cell* getCell(int i, int j);
	Cell* getInitial();
	Cell* getGoal();
	void outBoard(ofstream& file);
	int checkNum(string s);
};

#endif
