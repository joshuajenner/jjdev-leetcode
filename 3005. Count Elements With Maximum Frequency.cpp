// You are given an array nums consisting of positive integers.
//
// Return the total frequencies of elements in nums such that those elements all have the maximum frequency.
//
// The frequency of an element is the number of occurrences of that element in the array.

using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums)
    {
        unordered_map<int, int> numCounts;

        for (int num: nums)
        {
            numCounts[num]++;
        }

        int maxFreq = 0;
        int maxFreqSum = 0;

        for (auto& count: numCounts)
        {
            if (count.second > maxFreq)
            {
                maxFreq = count.second;
                maxFreqSum = count.second;
                continue;
            }
            else if (count.second == maxFreq)
            {
                maxFreqSum += count.second;
            }
        }

        return maxFreqSum;
    }
};