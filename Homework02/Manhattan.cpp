#include <iostream>
#include <cstdlib>
#include "Manhattan.h"

using namespace std;

/**
The euclidian distance from the current node to the goal node
@param i1 current node row
@param j1 current node column
@param i2 goal node row
@param j2 goal node column
@return float Euclidian distance
*/
float Manhattan::returnF(int path, int i1, int j1, int i2, int j2)
{
	return abs(i1-i2)+abs(j1-j2);
}
