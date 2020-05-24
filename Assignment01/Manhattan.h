#ifndef MANHATTAN_H
#define MANHATTAN_H

#include <iostream>
#include "Search.h"

using namespace std;

class Manhattan: public Search
{
public:
	float returnF(int path, int i1, int j1, int i2, int j2);
};

#endif
