//Given an m x n grid of characters board and a string word, return true if word exists in the grid.
//
//The word can be constructed from letters of sequentially adjacent cells, 
//where adjacent cells are horizontally or vertically neighboring.
//The same letter cell may not be used more than once.

#include <vector>
#include <string>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) 
    {
        std::vector<std::vector<int>> startCoords;

        for (int y = 0; y < board.size(); y++) 
        {
            for (int x = 0; x < board[x].size(); x++) 
            {
                if (board[y][x] == word[0]) 
                {
                    startCoords.push_back(std::vector<int>{y, x});
                }
            }
        }

        for (std::vector<int> startCoord : startCoords) 
        {
            std::vector<int> coord = startCoord;
            for (int i = 1; i < word.size(); i++) 
            {
                if (coord[0] > 0 && board[coord[0] - 1][coord[1]] == word[i])
                {
                    coord = std::vector<int>{ coord[0] - 1, coord[1] };
                    continue;
                }
                if (coord[0] < board.size() - 1 && board[coord[0] + 1][coord[1]] == word[i])
                {
                    coord = std::vector<int>{ coord[0] + 1, coord[1] };
                    continue;
                }
                if (coord[1] > 0 && board[coord[0]][coord[1] - 1] == word[i])
                {
                    coord = std::vector<int>{ coord[0], coord[1] - 1 };
                    continue;
                }
                if (coord[1] < board[0].size() - 1 && board[coord[0]][coord[1] + 1] == word[i])
                {
                    coord = std::vector<int>{ coord[0], coord[1] + 1 };
                    continue;
                }


                return false;
            }
        }

        return true;
    }
};