//Given an array nums containing n distinct numbers in the range[0, n], 
//return the only number in the range that is missing from the array.


#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int range = nums.size();
        int sum = (range * (range + 1)) / 2;

        for (int num: nums) {
            sum -= num;
        }

        return sum;
    }
};