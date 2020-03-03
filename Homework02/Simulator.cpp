#include <iostream>
#include <fstream>
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
			out << "Solution not found.\n" << endl;
		}
	}
	out.close();
	cout << "Searches successful, output located in \"output.txt\"" << endl;
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
			out << "Euclidian\n" << endl;
			break;
		case 2:
			search = new Manhattan();
			out << "Manhattan\n" << endl;
			break;
		case 3:
			search = new A_Euclidian();
			out << "A* Euclidian\n" << endl;
			break;
		case 4:
			search = new A_Manhattan();
			out << "A* Manhattan\n" << endl;
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
	board.getInitial()->setVisited();
	int nodes = 1;
	int steps = 0;
	while(!fringe.isEmpty())
	{
		Cell* c = fringe.removeFront();
		c->setStep();
		if(c == board.getGoal())
		{
			outPath(&board);
			board.outBoard(out);
			out << "\nPath Cost: " << c->getPath() << endl;
			out << "Number of Steps Taken: " << steps << endl;
			out << "Number of Nodes Searched: " << nodes << endl << endl;
			return 0;
		}
		if(board.getInitial() != c)
		{
			//c->setO();
			//board.outBoard(out);
			//out << endl;
		}
		nodes += searchNeighbors(c, &board, &fringe);
		steps++;
	}
	return -1;
}

/**
Searches the neighbors of a cell
@param c Current cell
@param board Board
@param fringe Fringe
@return nodes Number of nodes searched
*/
int Simulator::searchNeighbors(Cell* c, Board* board, DLL<Cell*>* fringe)
{
	int x = c->getX();
	int y = c->getY();
	int gx = board->getGoal()->getX();
	int gy = board->getGoal()->getY();
	int path = c->getPath()+1;
	int dimension = board->getDimension();
	int nodes = 0;
	if(x-1 >= 0)
	{
		Cell* c2 = board->getCell(x-1,y);
		if(!c2->isObstacle() && !c2->isVisited())
		{
			fringe->insert(search->returnF(path,x-1,y,gx,gy), c2);
			nodes++;
			c2->setPath(path);
			c2->setVisited();
		}
	}
	if(y-1 >= 0)
	{
		Cell* c2 = board->getCell(x,y-1);
		if(!c2->isObstacle() && !c2->isVisited())
		{
			fringe->insert(search->returnF(path,x,y-1,gx,gy), c2);
			nodes++;
			c2->setPath(path);
			c2->setVisited();
		}
	}
	if(x+1 < dimension)
	{
		Cell* c2 = board->getCell(x+1,y);
		if(!c2->isObstacle() && !c2->isVisited())
		{
			fringe->insert(search->returnF(path,x+1,y,gx,gy), c2);
			nodes++;
			c2->setPath(path);
			c2->setVisited();
		}
	}
	if(y+1 < dimension)
	{
		Cell* c2 = board->getCell(x,y+1);
		if(!c2->isObstacle() && !c2->isVisited())
		{
			fringe->insert(search->returnF(path,x,y+1,gx,gy), c2);
			nodes++;
			c2->setPath(path);
			c2->setVisited();
		}
	}
	return nodes;
}

/**
Prints the path taken to get to the goal node
@param board Pointer to board
*/
void Simulator::outPath(Board* board)
{
	int x = 0;
	int y = 0;
	int dimension = board->getDimension();
	DLL<Cell*> fringe;
	fringe.insert(board->getGoal()->getPath(), board->getGoal());
	Cell* c;
	while((c = fringe.removeFront())!= board->getInitial())
	{
		x = c->getX();
		y = c->getY();
		if(x-1 >= 0)
		{
			Cell* c2 = board->getCell(x-1,y);
			if((c2 == board->getInitial() || c2->getCharacter() == '.') && c2->isStep() && c2->getPath() == c->getPath() - 1)
			{
				fringe.insert(c2->getPath(), c2);
			}
		}
		if(y-1 >= 0)
		{
			Cell* c2 = board->getCell(x,y-1);
			if((c2 == board->getInitial() || c2->getCharacter() == '.') && c2->isStep() && c2->getPath() == c->getPath() - 1)
			{
				fringe.insert(c2->getPath(), c2);
			}
		}
		if(x+1 < dimension)
		{
			Cell* c2 = board->getCell(x+1,y);
			if((c2 == board->getInitial() || c2->getCharacter() == '.') && c2->isStep() && c2->getPath() == c->getPath() - 1)
			{
				fringe.insert(c2->getPath(), c2);
			}
		}
		if(y+1 < dimension)
		{
			Cell* c2 = board->getCell(x,y+1);
			if((c2 == board->getInitial() || c2->getCharacter() == '.') && c2->isStep() && c2->getPath() == c->getPath() - 1)
			{
				fringe.insert(c2->getPath(), c2);
			}
		}
		if(c != board->getGoal())
		{
			c->setO();
		}
	}
}
