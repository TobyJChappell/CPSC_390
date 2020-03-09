#include <iostream>
#include <fstream>
#include "Board.h"

using namespace std;

/**
Creates a board provided a valid filename
@param b The filename (consists of the size of the board followed by the board)
*/
Board::Board(string b)
{
	ifstream file(b);
	char character;
	string line;
	int count = 0;
	int i = 0;
	int j = 0;
	initial = new Cell();
	goal = new Cell();
	if(getline(file, line))
	{
		dimension = checkNum(line);
	}
	board = new Cell* [dimension];
	for(int x = 0; x < dimension; x++)
	{
		board[x] =  new Cell[dimension];
	}
	while(!file.eof())
	{
		file.get(character);
		if(character == '\n')
		{
			i++;
			j = 0;
		}
		else
		{
			board[i][j] = Cell(i,j,character);
			if(character == 'i')
			{
				initial = &board[i][j];
			}
			else if(character == 'g')
			{
				goal = &board[i][j];
			}
			j++;
		}
	}
	if(initial->getX() == -1)
	{
		cout << "ERROR: Initial space ('i') must be specified" << endl;
	}
	if(goal->getX() == -1)
	{
		cout << "ERROR: Goal space ('g') must be specified" << endl;
	}
	if(initial->getX() == -1 || goal->getX() == -1)
	{
		exit(EXIT_FAILURE);
	}
	file.close();
}

/**
Removes the board[][] from the heap
*/
Board::~Board()
{
	for(int x = 0; x < dimension; x++)
	{
		delete[] board[x];
	}
	delete[] board;
}

/**
Returns the dimension of the Board
*/
int Board::getDimension()
{
	return dimension;
}

/**
Returns the element of a board at a particular index
@param i Row
@param j Column
@return Cell* The cell at a location
*/
Cell* Board::getCell(int i, int j)
{
	return &board[i][j];
}

/**
Returns the initial element of the board
@return Cell* The initial cell
*/
Cell* Board::getInitial()
{
	return initial;
}

/**
Returns the goal element of the board
@return Cell* The goal cell
*/
Cell* Board::getGoal()
{
	return goal;
}

/**
Appends the board to a file
@param file The file being appended to
*/
void Board::outBoard(ofstream& file)
{
	for(int i = 0; i < dimension; i++)
	{
		for(int j = 0; j < dimension; j++)
		{
			file << board[i][j].getCharacter();
		}
		file << endl;
	}
}

/**
Checks a line to determine if it is a valid number
@param s The first line of the file
@return int The conversion of s into a number
*/
int Board::checkNum(string s)
{
	for(int i = 0; i < s.length(); i++)
	{
		if(!isdigit(s[i]))
		{
			cerr << "ERROR: Dimensions must be a number at the top of the file" << endl;
			exit(EXIT_FAILURE);
		}
	}
	int num = stoi(s);
	if(num < 2)
	{
		cerr << "ERROR: Dimensions must be greater than or equal to 2" << endl;
		exit(EXIT_FAILURE);
	}
	return num;
}
