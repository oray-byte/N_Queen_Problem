// Author: @Owen Miller-Fast (oray-byte)
// Date: 08/30/2021

#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>
#include <vector>
#include <set>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::getline;
using std::cin;
using std::set;

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
	bool solve(int n);
	bool isProblem(int m, int n);
	vector<vector<string>> board;
	int boardSize;
};
#endif
