#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// Tic-tac-toe is played by two players A and B on a 3 x 3 grid. The rules of Tic-Tac-Toe are:

// Players take turns placing characters into empty squares ' '.
// The first player A always places 'X' characters, while the second player B always places 'O' characters.
// 'X' and 'O' characters are always placed into empty squares, never on filled ones.
// The game ends when there are three of the same(non - empty) character filling any row, column, or diagonal.
// The game also ends if all squares are non - empty.
// No more moves can be played if the game is over.

// Given a 2D integer array moves where moves[i] = [rowi, coli] indicates that the ith move will be played on grid[rowi][coli]. 
// return the winner of the game if it exists(A or B).In case the game ends in a draw return "Draw".
// If there are still movements to play return "Pending".

// You can assume that moves is valid(i.e., it follows the rules of Tic - Tac - Toe), the grid is initially empty, and A will play first.

string tictactoe(vector<vector<int>>& moves);

string tictactoe(vector<vector<int>>& moves)
{
	bool isATurn = true;
	unordered_map<int, int> moveMap;

	for (vector<int> move : moves)
	{
		if (move[0] == 0)
		{
			moveMap[0] += getTurnValue(isATurn);
		} 
		else if (move[0] == 1)
		{
			moveMap[1] += getTurnValue(isATurn);
		}
		else if (move[0] == 2)
		{
			moveMap[2] += getTurnValue(isATurn);
		}

		if (move[1] == 0)
		{
			moveMap[3] += getTurnValue(isATurn);
		}
		else if (move[1] == 1)
		{
			moveMap[4] += getTurnValue(isATurn);
		}
		else if (move[1] == 2)
		{
			moveMap[5] += getTurnValue(isATurn);
		}

		if (moveIsInLeftDiagonal(move[0], move[1]))
		{
			moveMap[6] += getTurnValue(isATurn);
		}

		
		if (moveIsInRightDiagonal(move[0], move[1]))
		{
			moveMap[7] += getTurnValue(isATurn);
		}

		isATurn = !isATurn;
	}
	for (pair<int, int> winCondition : moveMap) 
	{
		if (winCondition.second == 3) {
			return "A";
		}
		else if (winCondition.second == -3) {
			return "B";
		}
	}	 
	if (moves.size() < 9)
	{
		return "Pending";
	}
	else {
		return "Draw";
	}
}

bool moveIsInLeftDiagonal(int x, int y)
{
	if ((x == 0 && y == 0) || (x == 1 && y == 1) || (x == 2 && y == 2))
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool moveIsInRightDiagonal(int x, int y)
{
	if ((x == 2 && y == 0) || (x == 1 && y == 1) || (x == 0 && y == 2))
	{
		return true;
	}
	else
	{
		return false;
	}
}


int getTurnValue(bool turnBool)
{
	if (turnBool)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

