#include <vector>
using namespace std;

// Given an integer array nums, move all 0's to the end of it 
// while maintaining the relative order of the non-zero elements.

// Note that you must do this in - place without making a copy of the array.

void moveZeroes(vector<int>& nums);


void moveZeroes(vector<int>& nums)
{
    for (int index = nums.size() - 1; index >= 0; index--)
    {
        if (nums[index] == 0)
        {
            nums.erase(nums.begin() + index);
            nums.push_back(0);
        }
    }
}