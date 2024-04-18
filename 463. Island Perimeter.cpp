// You are given row x col grid representing a map where grid[i][j] = 1 represents land 
// and grid[i][j] = 0 represents water.

// Grid cells are connected horizontally/vertically (not diagonally). 
// The grid is completely surrounded by water, and there is exactly one island 
// (i.e., one or more connected land cells).

// The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. 
// One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. 
// Determine the perimeter of the island.

#include <vector>
#include <iostream>

int GetTilePerimeter(std::vector<std::vector<int>>& grid, int x, int y)
{
    int height = grid.size();
    int width = grid[0].size();
    int perimeter = 0;

    if ((grid[y][x] == 1) && ((x + 1 >= width) || (x + 1 < width && grid[y][x + 1] == 0))) {
        perimeter++;
    }
    if ((grid[y][x] == 1) && ((x - 1 < 0) || (x - 1 >= 0 && grid[y][x - 1] == 0))) {
        perimeter++;
    }
    if ((grid[y][x] == 1) && ((y + 1 >= height) || (y + 1 < height && grid[y + 1][x] == 0))) {
        perimeter++;
    }
    if ((grid[y][x] == 1) && ((y - 1 < 0) || (y - 1 >= 0 && grid[y - 1][x] == 0))) {
        perimeter++;
    }

    return perimeter;
}

int islandPerimeter(std::vector<std::vector<int>>& grid) 
{
    int height = grid.size();
    int width = grid[0].size();
    int totalPerimeter = 0;

    for (int y = 0; y < height; y++) 
    {
        for (int x = 0; x < width; x++) 
        {
            totalPerimeter += GetTilePerimeter(grid, x, y);
        }
    }

    return totalPerimeter;
}




int main() 
{
    std::vector<std::vector<int>> data = { {0,1,0,0} ,{1,1,1,0},{0,1,0,0},{1,1,0,0} };
    std::cout << islandPerimeter(data);
    std::cin.get();
}