#include <iostream>
#include <cmath>
#include "A_Euclidian.h"

using namespace std;

/**
The A* euclidian distance from the current node to the goal node
@param path current path cost
@param i1 current node row
@param i2 goal node row
@param j1 current node column
@param j2 goal node column
@return float Euclidian distance
*/
float A_Euclidian::returnF(int path, int i1, int j1, int i2, int j2)
{
	return path+sqrt(pow(i1-i2,2)+pow(j1-j2,2));
}
