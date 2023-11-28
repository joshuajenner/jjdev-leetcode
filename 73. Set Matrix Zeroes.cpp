#include <vector>
#include <iostream>
using namespace std;

// Given an m x n integer matrix matrix, 
// if an element is 0, set its entire row and column to 0's.

// You must do it in place.

void setZeroes(vector<vector<int>>& matrix);

void setZeroes(vector<vector<int>>& matrix)
{
    int marked = -99;

    for (int x = 0; x < matrix.size(); x++)
    {
        for (int y = 0; y < matrix[x].size(); y++)
        {
            if (matrix[x][y] == 0)
            {
                for (int x2 = 0; x2 < matrix.size(); x2++)
                {
                    if (matrix[x2][y] != 0)
                    {
                        matrix[x2][y] = marked;
                    }
                }

                for (int y2 = 0; y2 < matrix[x].size(); y2++)
                {
                    if (matrix[x][y2] != 0)
                    {
                        matrix[x][y2] = marked;
                    }
                }
            }
        }
    }

    for (int x = 0; x < matrix.size(); x++)
    {
        for (int y = 0; y < matrix[x].size(); y++)
        {
            if (matrix[x][y] == marked)
            {
                matrix[x][y] = 0;
            }
        }
    }
}