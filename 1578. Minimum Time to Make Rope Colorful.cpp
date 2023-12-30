#include <vector>
#include <string>
#include <iostream>
using namespace std;

// Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

// Alice wants the rope to be colorful.She does not want two consecutive balloons to be of the same color, so she asks Bob for help.
// Bob can remove some balloons from the rope to make it colorful.
// You are given a 0 - indexed integer array neededTime where neededTime[i] is the time(in seconds) that Bob needs to remove the ith balloon from the rope.

// Return the minimum time Bob needs to make the rope colorful.

int minCost(string colors, vector<int>& neededTime);

int minCost(string colors, vector<int>& neededTime)
{
    int totalTime = 0;
    int ropeLength = colors.size();
    int currentHighest = 0;

    for (int index = 0; index < ropeLength; index++)
    {
        if (colors[index] == colors[index + 1])
        {
            if (index == 0)
            {
                totalTime += neededTime[index];
            }
            else if (colors[index - 1] != colors[index])
            {
                totalTime += neededTime[index];
            }

            totalTime += neededTime[index + 1];
            currentHighest = max(currentHighest, neededTime[index]);
            currentHighest = max(currentHighest, neededTime[index + 1]);
        }
        else
        {
            totalTime -= currentHighest;
            currentHighest = 0;
        }
    }

    return totalTime;
}