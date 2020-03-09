#include <iostream>
#include <fstream>
#include "Simulator.h"
using namespace std;

int main(int argc, char** argv)
{
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
	ifstream test;
	test.open(file);
	while(!test)
	{
		cout << "Please enter a valid file:" << endl;
		cin >> file;
		test.open(file);
	}
	Simulator s(file);
	s.run();
	return 0;
}
