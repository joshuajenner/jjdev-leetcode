// Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays.
// If there is no common integer amongst nums1 and nums2, return -1.

// Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        int nums1Size = nums1.size();
        int nums2Size = nums2.size();
        pair<unordered_set<int>::iterator, bool> result;
        unordered_set<int> num1Set;
        unordered_set<int> num2Set;

        for (int index = 0; index < max(nums1Size, nums2Size); index++)
        {
            if (index < nums1Size)
            {
                num1Set.insert(nums1[index]);
                if (num2Set.contains(nums1[index]))
                {
                    return nums1[index];
                }
            }
            if (index < nums2Size)
            {
                num2Set.insert(nums2[index]);
                if (num1Set.contains(nums2[index]))
                {
                    return nums2[index];
                }
            }
        }

        return -1;
    }
};