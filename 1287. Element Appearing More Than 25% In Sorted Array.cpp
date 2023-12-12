#include <vector>
#include <unordered_map>
using namespace std;

// Given an integer array sorted in non-decreasing order, 
// there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

int findSpecialInteger(vector<int>& arr);

int findSpecialInteger(vector<int>& arr)
{
	unordered_map<int, int> countMap;
	int minCount = arr.size() / 4;

	for (int num : arr) 
	{
		countMap[num] += 1;
		if (countMap[num] > minCount) {
			return num;
		}
	}
	return -1;
}