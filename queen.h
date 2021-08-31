// Author: @Owen Miller-Fast (oray-byte)
// Date: 08/30/2021

#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::getline;
using std::cin;

class Queen
{
public:
	Queen();
	Queen(int size);
	void solve();
	void setBoardSize(int size);
private:
	void initBoard();
	void printBoard();
	bool solve(int column);
	vector<vector<string>> board;
	int boardSize;
};
#endif
