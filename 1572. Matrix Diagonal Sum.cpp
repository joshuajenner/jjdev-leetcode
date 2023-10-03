#include <vector>
#include <iostream>
using namespace std;

// Given a square matrix mat, return the sum of the matrix diagonals.

// Only include the sum of all the elements on the primary diagonal and 
// all the elements on the secondary diagonal that are not part of the primary diagonal.

int diagonalSum(vector<vector<int>>& mat);

int diagonalSum(vector<vector<int>>& mat)
{
	int sum = 0;
	for (int index = 0; index < mat.size(); index++)
	{
		vector<int> leftDiagCoord = { index, index };
		vector<int> rightDiagCoord = { (int)mat.size() - 1 - index, index };

		if (leftDiagCoord == rightDiagCoord) {
			sum += mat[leftDiagCoord[0]][leftDiagCoord[1]];
		}
		else
		{
			sum += mat[leftDiagCoord[0]][leftDiagCoord[1]];
			sum += mat[rightDiagCoord[0]][rightDiagCoord[1]];
		}
	}
	return sum;
}