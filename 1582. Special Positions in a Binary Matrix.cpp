#include <vector>
using namespace std;

// Given an m x n binary matrix mat, return the number of special positions in mat.

// A position(i, j) is called special if mat[i][j] == 1 and 
// all other elements in row i and column j are 0 (rows and columns are 0 - indexed).

int numSpecial(vector<vector<int>>& mat);

int numSpecial(vector<vector<int>>& mat)
{
	int specialPositions = 0;

	for (int y = 0; y < mat.size(); y++) 
	{
		int specialIndexInRow = -1;
		for (int x = 0; x < mat[y].size(); x++)
		{
			if (mat[y][x] == 1) 
			{
				if (specialIndexInRow == -1) 
				{
					specialIndexInRow = x;
				}
				else {
					specialIndexInRow = -1;
					break;
				}
			}
		}
		if (specialIndexInRow != -1)
		{
			int specialCountInColumn = 0;
			for (int y = 0; y < mat.size(); y++) 
			{
				if (mat[y][specialIndexInRow] == 1) 
				{
					specialCountInColumn++;
				}
			}
			if (specialCountInColumn == 1) 
			{
				specialPositions++;
			}
		}
	}

	return specialPositions;
}