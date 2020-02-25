#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <iostream>
#include <fstream>
#include "DLL.h"
#include "Board.h"
#include "Cell.h"
#include "Search.h"
#include "Euclidian.h"
#include "A_Euclidian.h"
#include "Manhattan.h"
#include "A_Manhattan.h"

using namespace std;

class Simulator
{
private:
	Search* search;
	string filename;
public:
	Simulator(string b);
	~Simulator();
	void chooseSearch(int c, ofstream& out);
	int singleSearch(ofstream& out);
	void run();
};

#endif
