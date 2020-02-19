#ifndef A_EUCLIDIAN_H
#define A_EUCLIDIAN_H

#include <iostream>
#include "Search.h"

using namespace std;

class A_Euclidian: public Search
{
public:
	float returnF(int path, int i1, int j1, int i2, int j2);
};

#endif
