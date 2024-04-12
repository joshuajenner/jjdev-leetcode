//Given n non - negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

#include <vector>
#include <iostream>
#include <algorithm>


int trap(std::vector<int>& height) 
{
    int maxHeight = *std::max_element(height.begin(), height.end());
    int water = 0;

    for (int m = 0; m <= maxHeight; m++) 
    {
        int column = 0;
        int potentialWater = 0;
        bool firstWallFound = false;
        for (int &h : height)
        {
            if (h > 0)
            {
                if (!firstWallFound) {
                    firstWallFound = true;
                }
                else
                {
                    water += potentialWater;
                    potentialWater = 0;
                }
                h--;
            }
            else if (firstWallFound)
            {
                potentialWater++;
            }
            column++;
        }
    }
        
    return water;
}



int main() 
{
    std::vector<int> data = { 0,1,0,2,1,0,1,3,2,1,2,1 };

    trap(data);
    std::cin.get();
}