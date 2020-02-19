#include <iostream>
#include "Cell.h"

using namespace std;

Cell::Cell()
{
	x = 0;
	y = 0;
	path = 0;
	character = ' ';
	obstacle = false;
	initial = false;
	goal = false;
	visited = false;
}

Cell::Cell(int i, int j, char c)
{
	x = i;
	y = j;
	path = 0;
	character = c;
	obstacle = false;
	initial = false;
	goal = false;
	visited = false;
}

Cell::Cell(int i, int j, char c, bool obs, bool ini, bool g)
{
	x = i;
	y = j;
	path = 0;
	obstacle = obs;
	initial = ini;
	goal = g;
	character = c;
	visited = false;
}

int Cell::getX()
{
	return x;
}

int Cell::getY()
{
	return y;
}

int Cell::getPath()
{
	return path;
}

void Cell::setPath(int p)
{
	path = p;
}

char Cell::getCharacter()
{
	return character;
}

bool Cell::hasObstacle()
{
	return obstacle;
}

bool Cell::isInitial()
{
	return initial;
}

bool Cell::isGoal()
{
	return goal;
}

void Cell::setCharacter()
{
	character = 'o';
	visited = true;
}

bool Cell::isVisited()
{
	return visited;
}
