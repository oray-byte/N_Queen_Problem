// Author: @Owen Miller-Fast (oray-byte)
// Date: 08/30/2021

#include "queen.h"
Queen::Queen()
{
	this->setBoardSize(4);
	this->initBoard();
}

Queen::Queen(int size)
{
	this->setBoardSize(size);
	this->initBoard();
}

void Queen::solve()
{
	printBoard();
}

bool Queen::solve(int column)
{
	return false;
}

void Queen::initBoard()
{
	/* 
	* I create a temp vector that is a 1 x boardSize matrix then add temp boardSize times to make board a boardSize x boardSize matrix
	* This way, it shifts it from Time complexity: O(n^2) & Space complexity: O(1) to Time complexity O(n) & Space complexity: O(n)
	* I am shifting some time to space
	*/
	vector<string> temp;

	for (int i = 0; i < boardSize; i++)
	{
		temp.push_back(" ");
	}

	for (int i = 0; i < boardSize; i++)
	{
		board.push_back(temp);
	}
}

void Queen::setBoardSize(int size)
{
	/*
	* Ensures that the size is always greater than four so we do not have to worry about invalid boards.
	*/
	while (size < 4)
	{
		cout << "Size must be greater that four...\nPlease enter a new size value: ";
		cin >> size;
		cin.ignore();
		cin.clear();
	}

	boardSize = size;
}

void Queen::printBoard()
{
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			cout << "| " << board.at(i).at(j) << " ";
		}
		cout << "|" << endl;
	}
}