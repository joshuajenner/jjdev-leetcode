#include <vector>
using namespace std;

// An array is monotonic if it is either monotone increasing or monotone decreasing.

// An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

// Given an integer array nums, return true if the given array is monotonic, or false otherwise.

bool isMonotonic(vector<int> &nums);

bool isMonotonic(vector<int> &nums)
{
    bool isAscending = false;
    bool isDirectionFound = false;
    for (int index = 1; index < nums.size(); index++)
    {
        if (!isDirectionFound)
        {
            if (nums[index - 1] > nums[index])
            {
                isDirectionFound = true;
            }
            else if (nums[index - 1] < nums[index])
            {
                isAscending = true;
                isDirectionFound = true;
            }
        }
        else
        {
            if (isAscending)
            {
                if (nums[index - 1] > nums[index])
                {
                    return false;
                }
            }
            else
            {
                if (nums[index - 1] < nums[index])
                {
                    return false;
                }
            }
        }
    }
    return true;
}