#include <vector>
using namespace std;

// Given an m x n matrix, return all elements of the matrix in spiral order.

vector<int> spiralOrder(vector<vector<int>>& matrix);

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	// 0 > // 1 V // 2 < // 3 ^
	int direction = 0;
	int length = 0;
	int height = 0;
	int count = matrix[0].size() * matrix.size();
	vector<int> matrixSpiral = {};
	vector<int> position = { 0, 0 };

	for (int index = 0; index < count; count++) 
	{
		matrixSpiral.push_back(matrix[position[0]][position[1]]);

		// update position and direction
		switch (direction)
		{
			case 0:
				position[0] += 1;
				if (position[0] >= matrix[0].size() - 1 - length) {
					direction = 1;
					position[0] += 1;
				}
				break;
			case 1:
				position[1] += 1;
				if (position[1] >= matrix.size() - 1 - height) {
					direction = 2;
					position[1] += 1;
				}
				break;
			case 2:
				position[0] -= 1;
				if (position[0] < 0 + length) {
					direction = 3;
					position[0] -= 1;
				}
				break;
			case 3:
				position[1] -= 1;
				if (position[1] < 0 + height) {
					direction = 0;
					position[1] -= 1;
				}
				break;
		}
	}
	return matrixSpiral;
}