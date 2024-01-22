// You have a set of integers s, which originally contains all the numbers from 1 to n. 
// Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, 
// which results in repetition of one number and loss of another number.

// You are given an integer array nums representing the data status of this set after the error.

// Find the number that occurs twice and the number that is missing and return them in the form of an array.

using namespace std;
#include <vector>

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int size = nums.size();
        vector<bool> found(size + 1, false);
        int extraNum = 0;
        int sumAllInts = size * (1 + size) / 2;

        for (int num: nums) {
            if (found[num] == true) {
                extraNum = num;
            } 
            else {
                found[num] = true;
                sumAllInts -= num;
            }
        }

        return {extraNum, sumAllInts};
    }
};