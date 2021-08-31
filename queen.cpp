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
	
	if (solve(0))
	{
		printBoard();
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
}

bool Queen::solve(int n)
{
	/*
	* First, put a Q in (0, 0)
	*   Check for conflicts
	* If no, put a Q in (0, 1)
	*   Check for conflicts
	* Yes, so put a Q in (1, 1)
	*   Check for conlicts
	* Yes, so put a Q in (2, 1)
	*   Check for conflicts
	* No, so put a Q in (0, 2)
	*/
	if (n >= boardSize)
	{
		return true;
	}

	for (int i = 0; i < boardSize; i++)
	{
		if (!isProblem(i, n))
		{
			board.at(i).at(n) == "Q";

			if (solve(n + 1))
			{
				return true;
			}
			board.at(i).at(n) == " ";
		}
	}
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
	cout << endl;
}

bool Queen::isProblem(int m, int n)
{
	int columnUpperDiagnol = m - 1;
	int columnLowerDiagnol = m + 1;
	/*
	* If there is a problem, this function will return true
	* Otherwise, return false
	*/
	for (int i = (n - 1); i >= 0; i--)
	{
		if (board.at(m).at(i) == "Q")
		{
			return true;
		}
	}

	for (int i = (n - 1); i >= 0; i--)
	{
		if (columnUpperDiagnol >= 0)
		{
			if (board.at(columnUpperDiagnol).at(i) == "Q")
			{
				return true;
			}
			columnUpperDiagnol--;
		}

		if (columnLowerDiagnol < boardSize)
		{
			if (board.at(columnLowerDiagnol).at(i) == "Q")
			{
				return true;
			}
			columnLowerDiagnol++;
		}
	}

	return false;
}