// Given an array of integers arr, find the sum of min(b),
// where b ranges over every (contiguous) subarray of arr.
// Since the answer may be large, return the answer modulo 109 + 7.

// Constraints:

// 1 <= arr.length <= 3 * 104
// 1 <= arr[i] <= 3 * 104

using namespace std;
#include <vector>

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int size = arr.size();
        int sum = 0;

        for (int subArraySize = 1; subArraySize <= size; subArraySize++)
        {
            for (int offset = 0; offset <= size - subArraySize; offset++)
            {
                int smallestInt = -1;
                for (int index = 0; index < subArraySize; index++)
                {
                    if (smallestInt == -1 || arr[index + offset] < smallestInt)
                    {
                        smallestInt = arr[index + offset];
                    }
                }
                sum += smallestInt;
            }
        }
        return sum;
    }
};