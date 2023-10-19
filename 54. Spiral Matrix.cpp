#include <vector>
using namespace std;

// Given an m x n matrix, return all elements of the matrix in spiral order.

vector<int> spiralOrder(vector<vector<int>>& matrix);

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	enum Direction {goingLeft, goingDown, goingRight, goingUp};
	Direction direction = goingLeft;

	int topBorder = 0;
	int rightBorder = 0;
	int bottomBorder = 0;
	int leftBorder = 0;

	int count = matrix[0].size() * matrix.size();
	vector<int> matrixSpiral = {};
	vector<int> position = { 0, 0 };

	for (int index = 0; index < count; count++) 
	{
		matrixSpiral.push_back(matrix[position[0]][position[1]]);

		// update position and direction
		switch (direction)
		{
			case goingLeft:
				position[0] += 1;
				if (position[0] == (matrix[0].size() - rightBorder))
				{
					direction = goingDown;
					topBorder += 1;
				}
				break;
			case goingDown:
				position[1] += 1;
				if (position[1] == (matrix.size() - bottomBorder))
				{
					direction = goingRight;
					rightBorder += 1;
				}
				break;
			case goingRight:
				position[0] -= 1;
				if (position[0] == (matrix[0].size() - leftBorder))
				{
					direction = goingUp;
					bottomBorder += 1;
				}
				break;
			case goingUp:
				position[1] += 1;
				if (position[1] == (matrix.size() - topBorder))
				{
					direction = goingLeft;
					leftBorder += 1;
				}
				break;
		}
	}
	return matrixSpiral;
}