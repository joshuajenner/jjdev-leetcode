#include <vector>
using namespace std;

// Given a 2D integer array matrix, return the transpose of matrix.

// The transpose of a matrix is the matrix flipped over its main diagonal, 
// switching the matrix's row and column indices.

vector<vector<int>> transpose(vector<vector<int>>& matrix);

vector<vector<int>> transpose(vector<vector<int>>& matrix)
{
    int rows = matrix.size();
    int columns = matrix[0].size();
    vector<vector<int>> returnMatrix(columns, vector<int>(rows, 0));

    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < columns; x++)
        {
            returnMatrix[x][y] = matrix[y][x];
        }
    }

    return returnMatrix;
}