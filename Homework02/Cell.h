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
	bool obstacle;
	bool initial;
	bool goal;
	bool visited;
public:
	Cell();
	Cell(int i, int j, char c);
	Cell(int i, int j, char c, bool obs, bool ini, bool g);
	int getX();
	int getY();
	int getPath();
	void setPath(int p);
	char getCharacter();
	bool hasObstacle();
	bool isInitial();
	bool isGoal();
	void setCharacter();
	bool isVisited();
	void setVisited();
};

#endif
