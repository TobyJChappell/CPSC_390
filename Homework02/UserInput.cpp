#include <iostream>
#include <fstream>
#include <limits>
#include "UserInput.h"

/**
Checks to see if the user inputs a valid path
@param path Filename being checked
*/
void UserInput::checkPath(string& path)
{
	ifstream test;
	test.open(path);
	while(!test)
	{
		cout << endl;
		cout << "Please enter a valid file path:" << endl;
		cin >> path;
		test.open(path);
	}
}
