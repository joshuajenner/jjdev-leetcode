#include <vector>
using namespace std;

// An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down 
// the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). 
// If one or more of the surrounding cells of a cell is not present, we do not consider it in the average 
// (i.e., the average of the four cells in the red smoother).

// Given an m x n integer matrix img representing the grayscale of an image, 
// return the image after applying the smoother on each cell of it.

vector<vector<int>> imageSmoother(vector<vector<int>>& img);

vector<vector<int>> imageSmoother(vector<vector<int>>& img)
{
	vector<int> rowInit(img[0].size());
	vector<vector<int>> smoothedImage(img.size(), rowInit);

	for (int y = 0; y < img.size(); y++)
	{
		for (int x = 0; x < img[y].size(); x++)
		{
			int sum = 0;
			int numCount = 0;

			for (int sumY = max(0, y - 1); sumY < min(int(img.size()), y + 2); sumY++) 
			{
				for (int sumX = max(0, x - 1); sumX < min(int(img[y].size()), x + 2); sumX++) 
				{
					sum += img[sumY][sumX];
					numCount++;
				}
			}

			smoothedImage[y][x] = sum / numCount;
		}
	}

	return smoothedImage;
}