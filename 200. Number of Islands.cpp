// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water),
// return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
// You may assume all four edges of the grid are all surrounded by water.

#include <vector>
#include <algorithm>
#include <iostream>


// Go through the grid
// Whenever we encounter a gtile marked 1 we recursivley traverse all adjacents tiles
// marking them all 0
// increment the counter
// continue until all islands are visited

int numIslands(std::vector<std::vector<char>>& grid) {
    if (grid.empty() || grid[0].empty()) {
        return 0;
    }

    int numIslands = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1') {
                numIslands++;
                dfs(grid, i, j);
            }
        }
    }

    return numIslands;
}


void dfs(std::vector<std::vector<char>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
        return;
    }

    grid[i][j] = '0'; // mark as visited
    dfs(grid, i + 1, j); // down
    dfs(grid, i - 1, j); // up
    dfs(grid, i, j + 1); // right
    dfs(grid, i, j - 1); // left
}



int main() 
{
    std::vector<std::vector<char>> data = {
        {'1', '1', '1'},
        {'0', '1', '0'},
        {'1', '1', '1'},
    };

    std::cout << numIslands(data);
}