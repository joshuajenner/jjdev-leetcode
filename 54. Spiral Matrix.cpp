#include <vector>
using namespace std;

// Given an m x n matrix, return all elements of the matrix in spiral order.

vector<int> spiralOrder(vector<vector<int>>& matrix);

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	vector<int> matrixSpiral = {};
	
	if (matrix.empty() || matrix[0].empty())
	{
		return matrixSpiral;
	}

	int rows = matrix.size();
	int columns = matrix[0].size();
	
	int topBorder = 0;
	int rightBorder = columns - 1;
	int bottomBorder = rows - 1;
	int leftBorder = 0;


	while (leftBorder <= rightBorder && topBorder <= bottomBorder)
	{
		for (int index = leftBorder; index <= rightBorder; index++)
		{
			matrixSpiral.push_back(matrix[topBorder][index]);
		}
		topBorder++;

		for (int index = topBorder; index <= bottomBorder; index++)
		{
			matrixSpiral.push_back(matrix[index][rightBorder]);
		}
		rightBorder--;

		if (topBorder <= bottomBorder)
		{
			for (int index = rightBorder; index >= leftBorder; index--)
			{
				matrixSpiral.push_back(matrix[bottomBorder][index]);
			}
			bottomBorder--;
		}

		if (leftBorder <= rightBorder)
		{
			for (int index = bottomBorder; index >= topBorder; index--)
			{
				matrixSpiral.push_back(matrix[index][leftBorder]);
			}
			leftBorder++;
		}
	}
	return matrixSpiral;
}