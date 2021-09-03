// Author: @Owen Miller-Fast (oray-byte)
// Date: 08/30/2021

#include "queen.h"
Queen::Queen()
{
	int size = 0;
	do
	{
		cout << "Enter desired size: ";
		cin >> size;
		cin.clear();
		cin.ignore();
	} while (size < 4);

	this->setBoardSize(size);
	this->initBoard();
}

void Queen::solve()
{
	// Just encapsulating the function.
	if (solve(0))
	{
		printBoard();
	}
	else
	{
		cout << "Does not exist..." << endl;
	}
}

bool Queen::solve(int n)
{
	/*
	* This is the recursive function that solves the problem.
	* First, we check if n is >= boardSize. If it is, we have found a solution. 
	* Second, we have the for loop. It's job is to go through each possible location in each column (each row) and check if it works. (See isProblem() for critria)
	* Next, we check if there is a problem at the current location (i, n) in the matrix n x n
	* If there is no position that works, we return false.
	* If there is not a problem, we place a 'Q' at that position since it is valid.
	* Then, we call the function within the if statement. When it returns true, we have found a solution.
	* The recursion works by finding a location that works in the current column then calls the function for the next column. If there is not a valid position, return false and find another row position for the current column.
	*   However, if n is ever >= boardSize then we found a solution since there is only (boardSize - 1) columns.
	*/
	
	if (n >= boardSize) // If this statement is true, then that means the last n was the final column and satisfied the conditions, meaning a solution was found.
	{
		return true; // Base condition
	}

	for (int i = 0; i < boardSize; i++)
	{
		if (!isProblem(i, n)) // If not a problem, continue with recursion
		{
			board.at(i).at(n) = "Q"; // Sets a Q on board

			if (solve(n + 1)) 
			{
				return true;
			}
			board.at(i).at(n) = " "; // Allows for back-tracking incase there is no solution with current board and all possible rows in n + 1 column
		}
	}
	return false; // Only occurs when there is no possible combination with current board and 
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
	/*
	* Checks to see if desired position (m, n) in matrix is valid. If it is invalid, we return true.
	* First, we acknowledge that we do not have to check positions in front of us because we are placing Q's left to right so there are no Q's on the right to check. This cuts out half of the searching.
	* I declared columUpperDiagonal and columnLowerDiagonal to simplify searching diagonally. More on that later.
	* We begin by checking to the right of the desired location. If there was member function for vectors like myVector.count('Q'), then I would just call that but there is not unfortunately.
	* Next, we check the upper and lower diagonals from the desired location. columnUpperDiagonal and columnLowerDiagonal are initialized with an offset of one from the desired location's height in the matrix.
	*   This is because we are only checking to the left of the desired so if we just decrement i down from the desired position, we will check both diagonals.
	*   Additionally, we need to check if columnUpperDiagonal and columnLowerDiagonal are within bounds of the board so we do not cause a seg fault
	*/
	int columnUpperDiagonal = m - 1;
	int columnLowerDiagonal = m + 1;

	for (int i = (n - 1); i >= 0; i--)
	{
		if (board.at(m).at(i) == "Q")
		{
			return true;
		}

		if (columnUpperDiagonal >= 0)
		{
			if (board.at(columnUpperDiagonal).at(i) == "Q")
			{
				return true;
			}
			columnUpperDiagonal--;
		}

		if (columnLowerDiagonal < boardSize)
		{
			if (board.at(columnLowerDiagonal).at(i) == "Q")
			{
				return true;
			}
			columnLowerDiagonal++;
		}
	}
	/*
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
	*/
	return false;
}