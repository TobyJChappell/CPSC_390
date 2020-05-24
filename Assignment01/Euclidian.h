#ifndef EUCLIDIAN_H
#define EUCLIDIAN_H

#include <iostream>
#include "Search.h"

using namespace std;

class Euclidian: public Search
{
public:
	float returnF(int path, int i1, int j1, int i2, int j2);
};

#endif
