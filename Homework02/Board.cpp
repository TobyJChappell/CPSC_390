#include <iostream>
#include <fstream>
#include "Board.h"

using namespace std;

/**
Creates a board provided a valid filename
@param b The filename (consists of a 2 numbers and a board)
*/
Board::Board(string b)
{
	ifstream file(b);
	char character;
	string line;
	int count = 0;
	int i = 0;
	int j = 0;
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
			if(character == 'i')
			{
				board[i][j] = Cell(i,j,character,false,true,false);
				initial = &board[i][j];
			}
			else if(character == 'g')
			{
				board[i][j] = Cell(i,j,character,false,false,true);
				goal = &board[i][j];
			}
			else if(character == '+')
			{
				board[i][j] = Cell(i,j,character,true,false,false);
			}
			else
			{
				board[i][j] = Cell(i,j,character);
			}
			j++;
		}
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
*/
Cell* Board::getCell(int i, int j)
{
	return &board[i][j];
}

void Board::setO(int i, int j)
{
	board[i][j].setCharacter();
}

Cell* Board::getInitial()
{
	return initial;
}

Cell* Board::getGoal()
{
	return goal;
}

/**
Appends the board to a file
@param filename The name of a file
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
Checks a line to determine if it is a number
@param s The first line of the file
@return int The conversion of s into a number
*/
int Board::checkNum(string s)
{
	for(int i = 0; i < s.length(); i++)
	{
		if(!isdigit(s[i]))
		{
			cerr << "ERROR: Dimensions must be numbers at the top of the file" << endl;
			exit(EXIT_FAILURE);
		}
	}
	int num = stoi(s);
	if(num < 1)
	{
		cerr << "ERROR: Dimensions must be greater than 1" << endl;
		exit(EXIT_FAILURE);
	}
	return num;
}
