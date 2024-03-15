//Given an integer array nums, return an array answer such that answer[i] 
//is equal to the product of all the elements of nums except nums[i].
//
//The product of any prefix or suffix of nums is guaranteed to fit in a 32 - bit integer.
//
//You must write an algorithm that runs in O(n) time and without using the division operation.

#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums)
    {
        int size = nums.size();
        std::vector<int> leftProducts(size, nums[0]);
        std::vector<int> rightProducts(size, nums[size - 1]);
        std::vector<int> resultProducts(size, 0);

        for (int i = 1; i < size; i++)
        {
            leftProducts[i] = nums[i] * leftProducts[i - 1];
            rightProducts[size - i - 1] = nums[size - i - 1] * rightProducts[size - i];
        }

        for (int i = 0; i < size; i++)
        {
            if (i == 0) {
                resultProducts[i] = rightProducts[i + 1];
            }
            else if (i == size - 1) {
                resultProducts[i] = leftProducts[i - 1];
            }
            else {
                resultProducts[i] = leftProducts[i - 1] * rightProducts[i + 1];
            }

        }

        return resultProducts;
    }
};