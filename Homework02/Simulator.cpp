#include <iostream>
#include <fstream>
#include <unistd.h>

#include "Simulator.h"
using namespace std;

/**
Creates a board from an input file
@param b The name of a valid input file
*/
Simulator::Simulator(string b)
{
	filename = b;
}

/**
Destructor
*/
Simulator::~Simulator()
{
	delete search;
}

/**
Runs all four search algorithms and outputs it to a file
*/
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
Chooses a search algorithm and appends the search name to the file
@param c Which search to choose
@param out File being appended to
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
Performs a single search algorithm and appends resulting board, path cost, and number of nodes to output file
@param out File being appended to
@return int 0 if search was success
*/
int Simulator::singleSearch(ofstream& out)
{
	Board board(filename);
	DLL<Cell*> fringe;
	fringe.insert(0, board.getInitial());
	int path = 0;
	int nodes = 1;
	int dimension = board.getDimension();
	int x = 0;
	int y = 0;
	int gx = board.getGoal()->getX();
	int gy = board.getGoal()->getY();

	while(!fringe.isEmpty())
	{
		Cell* c = fringe.removeFront();
		if(c == board.getGoal())
		{
			board.outBoard(out);
			out << "\nPath Cost: " << c->getPath() << endl;
			out << "Number of Nodes: " << nodes << endl;
			return 0;
		}
		x = c->getX();
		y = c->getY();
		path = c->getPath()+1;
		if(!c->isInitial())
		{
			c->setO();
		}
		else
		{
			board.getInitial()->setVisited();
		}
		if(x-1 >= 0)
		{
			Cell* c2 = board.getCell(x-1,y);
			if(!c2->isObstacle() && !c2->isVisited())
			{
				fringe.insert(search->returnF(path,x-1,y,gx,gy), c2);
				nodes++;
				c2->setPath(path);
				c2->setVisited();
			}
		}
		if(y-1 >= 0)
		{
			Cell* c2 = board.getCell(x,y-1);
			if(!c2->isObstacle() && !c2->isVisited())
			{
				fringe.insert(search->returnF(path,x,y-1,gx,gy), c2);
				nodes++;
				c2->setPath(path);
				c2->setVisited();
			}
		}
		if(x+1 < dimension)
		{
			Cell* c2 = board.getCell(x+1,y);
			if(!c2->isObstacle() && !c2->isVisited())
			{
				fringe.insert(search->returnF(path,x+1,y,gx,gy), c2);
				nodes++;
				c2->setPath(path);
				c2->setVisited();
			}
		}
		if(y+1 < dimension)
		{
			Cell* c2 = board.getCell(x,y+1);
			if(!c2->isObstacle() && !c2->isVisited())
			{
				fringe.insert(search->returnF(path,x,y+1,gx,gy), c2);
				nodes++;
				c2->setPath(path);
				c2->setVisited();
			}
		}
	}
	board.outBoard(out);
	return -1;
}
