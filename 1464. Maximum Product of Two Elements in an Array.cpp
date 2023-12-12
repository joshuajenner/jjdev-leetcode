#include <vector>
using namespace std;

// Given the array of integers nums, you will choose two different indices i and j of that array. 
// Return the maximum value of (nums[i]-1)*(nums[j]-1).

int maxProduct(vector<int>& nums);

int maxProduct(vector<int>& nums)
{
	int value1 = 0;
	int value2 = 0;

	for (int index = 0; index < nums.size(); index++ ) 
	{
		if (nums[index] >= value1) {
			value2 = value1;
			value1 = nums[index];
		}
		else if (nums[index] > value2) 
		{
			value2 = nums[index];
		}
	}
	return (value1 - 1) * (value2 - 1);
}