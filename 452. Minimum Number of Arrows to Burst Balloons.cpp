//There are some spherical balloons taped onto a flat wall that represents the XY - plane.
//The balloons are represented as a 2D integer array points where points[i] = [x start, x end] 
//denotes a balloon whose horizontal diameter stretches between x start and x end.
//You do not know the exact y - coordinates of the balloons.
//
//Arrows can be shot up directly vertically (in the positive y - direction) from different points along 
//the x - axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend.
//There is no limit to the number of arrows that can be shot.A shot arrow keeps traveling up infinitely, 
//bursting any balloons in its path.
//
//Given the array points, return the minimum number of arrows that must be shot to burst all balloons.


#include <vector>
#include <algorithm>


class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points)
    {
        std::sort(points.begin(), points.end());
        int prevIndex = points[0][1];
        int arrows = 1;

        for (std::vector<int> point: points)
        {
            if (prevIndex >= point[0])
            {
                prevIndex = std::min(point[1], prevIndex);
            }
            else {
                prevIndex = point[1];
                arrows++;
            }
        }

        return arrows;
    }
};