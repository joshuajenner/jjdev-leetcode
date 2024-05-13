// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. 
// You may assume that the majority element always exists in the array.

#include <vector>

int majorityElement(std::vector<int>& nums) {
    int count = 0;    
    int element = 0; 

    for (int num: nums) 
    {
        if (count == 0) 
        {
            element = num;
        }

        if (element == num) 
        {
            count++;
        } 
        else 
        {
            count--;
        }
    }

    return element; 
}