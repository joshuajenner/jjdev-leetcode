#include <vector>
#include <iostream>
using namespace std;

// Given an m x n integer matrix matrix, 
// if an element is 0, set its entire row and column to 0's.

// You must do it in place.

void setZeroes(vector<vector<int>>& matrix);

void setZeroes(vector<vector<int>>& matrix)
{
    int rowMark = -2;
    int colMark = -3;

    for (int y = 0; y < matrix.size(); y++) {
        for (int x = 0; x < matrix[y].size(); x++)
        {
            if (matrix[y][x] == 0)
            {
                // cout << to_string(y) + " , " + to_string(x);
                // cout << "\n";
                matrix[0][x] = rowMark;
                matrix[y][0] = colMark;
            }
        }
    }

    for (int y = 0; y < matrix.size(); y++)
    {
        if (matrix[y][0] == colMark)
        {
            // cout << to_string(y) + " Row \n";
            for (int x = 0; x < matrix[y].size(); x++)
            {
                matrix[y][x] = 0;
            }
        }
    }

    for (int x = 0; x < matrix[0].size(); x++)
    {
        if (matrix[0][x] == rowMark)
        {
            // cout << to_string(x) + " Col \n";
            for (int y = 0; y < matrix.size(); y++)
            {
                matrix[y][x] = 0;
            }
        }
    }
}