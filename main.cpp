#include <iostream>
#include <string>
using namespace std;

#include <vector>

bool CheckCoord(std::vector<std::vector<char>>& board, std::vector<int> prev, std::vector<int> curr, std::string& word, int i);

bool exist(std::vector<std::vector<char>>& board, std::string word)
{
    bool doesWordExist = false;
    std::vector<int> prev{ -1, -1 };

    for (int y = 0; y < board.size(); y++)
    {
        for (int x = 0; x < board[y].size(); x++)
        {
            if (board[y][x] == word[0])
            {
                doesWordExist = doesWordExist || CheckCoord(board, prev, std::vector<int>{y, x}, word, 1);
            }
        }
    }

    return doesWordExist;
}

bool CheckCoord(std::vector<std::vector<char>>& board, std::vector<int> prev, std::vector<int> curr, std::string& word, int i)
{
    char checkChar = word[i];

    if (curr[0] > 0)
    {
        std::vector<int>up{ curr[0] - 1, curr[1] };
        if (up != prev && board[up[0]][up[1]] == word[i])
        {
            return CheckCoord(board, curr, up, word, i + 1);
        }
    }
    if (curr[0] < board.size() - 1)
    {
        std::vector<int>down{ curr[0] + 1, curr[1] };
        if (down != prev && board[down[0]][down[1]] == word[i])
        {
            return CheckCoord(board, curr, down, word, i + 1);
        }
    }
    if (curr[1] > 0)
    {
        std::vector<int>left{ curr[0], curr[1] - 1 };
        if (left != prev && board[left[0]][left[1]] == word[i])
        {
            return CheckCoord(board, curr, left, word, i + 1);
        }
    }
    if (curr[1] < board[0].size() - 1)
    {
        std::vector<int>right{ curr[0], curr[1] + 1 };
        if (right != prev && board[right[0]][right[1]] == word[i])
        {
            return CheckCoord(board, curr, right, word, i + 1);
        }
    }

    if (i == word.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    std::vector<char> row1{ 'A', 'B', 'C', 'E' };
    std::vector<char> row2{ 'S', 'F', 'C', 'S' };
    std::vector<char> row3{ 'A', 'D', 'E', 'E' };

    std::vector<std::vector<char>> grid{ row1, row2, row3 };

    std::cout << exist(grid, "ABCCED");

    std::cin.get();
};

