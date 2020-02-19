#include <iostream>
#include <fstream>
#include <unistd.h>

#include "Simulator.h"
using namespace std;

/**
Creates a board from an input file and prompts the user to choose a boundary mode and output
@param b The name of a valid input file
*/
Simulator::Simulator(string b)
{
	board = new Board(b);
	fringe = new DLL<Cell*>;
	fringe->insert(0, board->getInitial());
}

/**
Destructor
*/
Simulator::~Simulator()
{
	delete board;
	delete search;
	delete fringe;
}

void Simulator::run()
{
	ofstream out;
	out.open("output.txt");
	for(int i = 1; i <= 4; i++)
	{
		chooseSearch(i, out);
		if(singleSearch(out) == -1)
		{
			out << "\nSolution not found." << endl;
		}
	}
	out.close();
}

/**
Prompts the user to choose a search and assigns it to search
*/
void Simulator::chooseSearch(int c, ofstream& out)
{
	switch(c)
	{
		case 1:
			search = new Euclidian();
			out << "\nEuclidian\n" << endl;
			break;
		case 2:
			search = new Manhattan();
			out << "\nManhattan\n" << endl;
			break;
		case 3:
			search = new A_Euclidian();
			out << "\nA* Euclidian\n" << endl;
			break;
		case 4:
			search = new A_Manhattan();
			out << "\nA* Manhattan\n" << endl;
			break;
	}
}

/**
Simulates Game of Life until it has stabilized or surpasses 1000 generations
*/
int Simulator::singleSearch(ofstream& out)
{
	int path = 0;
	int dimension = board->getDimension();
	int x = 0;
	int y = 0;
	int gx = board->getGoal()->getX();
	int gy = board->getGoal()->getY();
	while(!fringe->isEmpty())
	{
		Cell* c = fringe->removeFront();
		if(c == board->getGoal())
		{
			board->outBoard(out);
			out << "\nPath Cost: " << c->getPath() << endl;
			out << "Number of Nodes: " << fringe->getSize() << endl;
			return 0;
		}
		x = c->getX();
		y = c->getY();
		if(!c->isInitial())
		{
			board->setO(x,y);
		}
		path = c->getPath()+1;
		if(x-1 >= 0)
		{
			Cell* c2 = board->getCell(x-1,y);
			if(!c2->hasObstacle() && !c2->isVisited())
			{
				fringe->insert(search->returnF(path,x-1,y,gx,gy), c2);
				c2->setPath(path);
			}
		}
		if(y-1 >= 0)
		{
			Cell* c2 = board->getCell(x,y-1);
			if(!c2->hasObstacle() && !c2->isVisited())
			{
				fringe->insert(search->returnF(path,x,y-1,gx,gy), c2);
				c2->setPath(path);
			}
		}
		if(x+1 < dimension)
		{
			Cell* c2 = board->getCell(x+1,y);
			if(!c2->hasObstacle() && !c2->isVisited())
			{
				fringe->insert(search->returnF(path,x+1,y,gx,gy), c2);
				c2->setPath(path);
			}
		}
		if(y+1 < dimension)
		{
			Cell* c2 = board->getCell(x,y+1);
			if(!c2->hasObstacle() && !c2->isVisited())
			{
				fringe->insert(search->returnF(path,x,y+1,gx,gy), c2);
				c2->setPath(path);
			}
		}
	}
	board->outBoard(out);
	return -1;
}

/**
Determines if parameter is a number as well as in the range specified. If not, asks user for a number until one is inputted.
@param num Variable being checked
*/
void Simulator::checkNum(int& num)
{
	while(!cin || num < 1 || num > 4)
	{
		cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Please enter a valid number:" << endl;
		cin >> num;
	}
}
