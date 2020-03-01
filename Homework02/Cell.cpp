#include <iostream>
#include "Cell.h"

using namespace std;

/**
Default cell constructor
*/
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
	step = false;
}

/**
Overloaded cell constructor
@param i X coordinate
@param j Y coordinate
@param c Character
*/
Cell::Cell(int i, int j, char c)
{
	x = i;
	y = j;
	character = c;
	path = 0;
	initial = false;
	goal = false;
	obstacle = false;
	visited = false;
	step = false;
	if(c == 'i')
	{
		initial = true;
	}
	else if(c == 'g')
	{
		goal = true;
	}
	else if(c == '+')
	{
		obstacle = true;
	}
}

/**
Returns x coordinate
@return int X
*/
int Cell::getX()
{
	return x;
}

/**
Returns y coordinate
@return int Y
*/
int Cell::getY()
{
	return y;
}

/**
Returns path cost
@return int Path
*/
int Cell::getPath()
{
	return path;
}

/**
Sets path cost to some value
@param p Path cost
*/
void Cell::setPath(int p)
{
	path = p;
}

/**
Returns the character
@return char Character
*/
char Cell::getCharacter()
{
	return character;
}

/**
Returns cell is an obstacle
@return bool Obstacle
*/
bool Cell::isObstacle()
{
	return obstacle;
}

/**
Returns cell is the intial
@return bool Initial
*/
bool Cell::isInitial()
{
	return initial;
}

/**
Returns cell is the goal
@return bool Goal
*/
bool Cell::isGoal()
{
	return goal;
}

/**
Returns if is visited
@return bool Visited
*/
bool Cell::isVisited()
{
	return visited;
}

/**
Sets to visited
*/
void Cell::setVisited()
{
	visited = true;
}

/**
Sets a cell to 'o'
*/
void Cell::setO()
{
	character = 'o';
}

bool Cell::isStep()
{
	return step;
}

void Cell::setStep()
{
	step = true;
}
