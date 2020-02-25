#ifndef CELL_H
#define CELL_H

#include <iostream>

using namespace std;

class Cell
{
private:
	int x;
	int y;
	int path;
	char character;
	bool initial;
	bool goal;
	bool obstacle;
	bool visited;
public:
	Cell();
	Cell(int i, int j, char c);
	int getX();
	int getY();
	int getPath();
	void setPath(int p);
	char getCharacter();
	bool isObstacle();
	bool isInitial();
	bool isGoal();
	bool isVisited();
	void setVisited();
	void setO();
};

#endif
