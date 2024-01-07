#include <vector>
#include <unordered_map>
using namespace std;

// You are given a 0-indexed array nums consisting of positive integers.

// There are two types of operations that you can apply on the array any number of times :

// Choose two elements with equal values and delete them from the array.
// Choose three elements with equal values and delete them from the array.
// Return the minimum number of operations required to make the array empty, or -1 if it is not possible.


int minOperations(vector<int>& nums);

int minOperations(vector<int>& nums)
{
	int numOfOperations = 0;
	unordered_map<int, int> numCount;

	for (int num: nums) 
	{
		numCount[num]++;
	}

	for (auto iter = numCount.begin(); iter != numCount.end(); iter++) 
	{
		if (iter->second == 1) 
		{
			return -1;
		}
		else
		{
			int remainder = iter->second % 3;

			if (remainder == 0) 
			{
				numOfOperations += iter->second / 3;
			}
			else if (remainder == 2)
			{
				numOfOperations += (iter->second / 3) + 1;
			}
			else if (remainder == 1) 
			{
				if (iter->second < 7) 
				{
					numOfOperations += 2;
				}
				else
				{
					numOfOperations += ((iter->second - 4) / 3) + 2;
				}
			}
			
			/*int checkCount = iter->second;
			while (checkCount > 0)
			{
				if (checkCount >= 3)
				{
					checkCount -= 3;
					numOfOperations++;
				}
				else if (checkCount == 4)
				{
					checkCount -= 4;
					numOfOperations += 2;
				}
				else
				{
					checkCount -= 2;
					numOfOperations++;
				}
			}*/

		}
	}

	return numOfOperations;
}