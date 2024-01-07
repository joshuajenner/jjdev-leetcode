#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:

// The 2D array should contain only the elements of the array nums.
// Each row in the 2D array contains distinct integers.
// The number of rows in the 2D array should be minimal.
// Return the resulting array.If there are multiple answers, return any of them.

// Note that the 2D array can have a different number of elements on each row.

vector<vector<int>> findMatrix(vector<int>& nums);

vector<vector<int>> findMatrix(vector<int>& nums)
{
	vector<vector<int>> returnVector{ {} };
	unordered_map<int, int> highestPlacedIndex;

	for (int num : nums)
	{
		if (highestPlacedIndex.find(num) == highestPlacedIndex.end())
		{
			highestPlacedIndex[num] = 0;
			returnVector[0].push_back(num);
		}
		else
		{
			highestPlacedIndex[num]++;

			if (highestPlacedIndex[num] < returnVector.size()) 
			{
				returnVector[highestPlacedIndex[num]].push_back(num);
			}
			else
			{
				returnVector.push_back({ num });
			}
		}
	}

	return returnVector;
}