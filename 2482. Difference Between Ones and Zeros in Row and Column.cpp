#include <vector>
using namespace std;

// You are given a 0-indexed m x n binary matrix grid.

// A 0 - indexed m x n difference matrix diff is created with the following procedure :

// Let the number of ones in the ith row be onesRowi.
// Let the number of ones in the jth column be onesColj.
// Let the number of zeros in the ith row be zerosRowi.
// Let the number of zeros in the jth column be zerosColj.
// diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
// Return the difference matrix diff.


vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid);

vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid)
{
	vector<int> rows(grid[0].size());
	vector<vector<int>> differenceMatrix(grid.size(), rows);

	vector<int> rowsOne(grid.size(), -1);
	vector<int> colsOne(grid[0].size(), -1);
	vector<int> rowsZero(grid.size(), -1);
	vector<int> colsZero(grid[0].size(), -1);

	for (int y = 0; y < grid.size(); y++)
	{
		for (int x = 0; x < grid[y].size(); x++)
		{
			int onesInRow = 0;
			int onesInCol = 0;
			int zerosInRow = 0;
			int zerosInCol = 0;

			if (rowsOne[y] == -1)
			{
				for (int checkX = 0; checkX < grid[y].size(); checkX++)
				{
					if (grid[y][checkX] == 1)
					{
						onesInRow++;
					}
					else
					{
						zerosInRow++;
					}
				}
				rowsOne[y] = onesInRow;
				rowsZero[y] = zerosInRow;
			}

			if (colsOne[x] == -1)
			{
				for (int checkY = 0; checkY < grid.size(); checkY++)
				{
					if (grid[checkY][x] == 1)
					{
						onesInCol++;
					}
					else
					{
						zerosInCol++;
					}
				}
				colsOne[x] = onesInCol;
				colsZero[x] = zerosInCol;
			}
			differenceMatrix[y][x] = rowsOne[y] + colsOne[x] - rowsZero[y] - colsZero[x];
		}
	}

	return differenceMatrix;
}

// cout << rowsOne[x] << " + " << colsOne[y] << " - " << rowsZero[x] << " - " << colsZero[y] << "\n";