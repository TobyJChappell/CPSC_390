#include <iostream>
#include <fstream>
#include "Simulator.h"
#include "UserInput.h"

using namespace std;

int main(int argc, char** argv)
{
	UserInput u;
	string file;
	if(argc > 1)
	{
		file = argv[1];
	}
	else
	{
		cout << "Please input a file:" << endl;
		cin >> file;
	}
	u.checkPath(file);
	Simulator s(file);
	s.run();
	return 0;
}
