#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <limits>

using namespace std;

/**
Search is an astract class so that when once a search is chosen, Simulator will assign that search to this class. Thus, the behavior of Simulator remains unaltered no matter what search the user selects.
*/
class Search
{
public:
	virtual float returnF(int path, int i1, int i2, int j1, int j2) {return 0;}
};

#endif
