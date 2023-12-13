#include <vector>
using namespace std;

// On a 2D plane, there are n points with integer coordinates points[i] = [xi, yi]. 
// Return the minimum time in seconds to visit all the points in the order given by points.

// You can move according to these rules :

// In 1 second, you can either :
// move vertically by one unit,
// move horizontally by one unit, or
// move diagonally sqrt(2) units(in other words, move one unit vertically then one unit horizontally in 1 second).
// You have to visit the points in the same order as they appear in the array.
// You are allowed to pass through points that appear later in the order, but these do not count as visits.

int minTimeToVisitAllPoints(vector<vector<int>>& points);

int minTimeToVisitAllPoints(vector<vector<int>>& points)
{
	int minTime = 0;

	for (int index = 0; index < points.size()-1; index++) 
	{
		int xDifference = abs(points[index][0] - points[index + 1][0]);
		int yDifference = abs(points[index][1] - points[index + 1][1]);
		int maxDifference = max(xDifference, yDifference);

		minTime += maxDifference;
	}

	return minTime;
}