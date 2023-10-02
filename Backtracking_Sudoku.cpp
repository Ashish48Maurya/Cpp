#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<char>> &sudokuBoard, int row, int col, char num)
{
    // Check for Column
    for (int i = 0; i < 9; i++)
    {
        if (sudokuBoard[i][col] == num)
        {
            return false;
        }
    }

    // Check for Row
    for (int j = 0; j < 9; j++)
    {
        if (sudokuBoard[row][j] == num)
        {
            return false;
        }
    }

    // Check in 3x3 Matrix
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (sudokuBoard[i][j] == num)
            {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(vector<vector<char>> &sudokuBoard, int row, int col)
{
    if (row == 9)
    {
        return true; // Solved all cells
    }

    if (col == 9)
    {
        return solveSudoku(sudokuBoard, row + 1, 0); // Move to the next row
    }

    if (sudokuBoard[row][col] == '.')
    {
        for (char num = '1'; num <= '9'; num++)
        {
            if (isSafe(sudokuBoard, row, col, num))
            {
                sudokuBoard[row][col] = num;
                if (solveSudoku(sudokuBoard, row, col + 1))
                {
                    return true; // Found a solution
                }
                sudokuBoard[row][col] = '.'; // Backtrack
            }
        }
        return false; // No valid number found, backtrack
    }
    else
    {
        return solveSudoku(sudokuBoard, row, col + 1); // Move to the next cell
    }
}

int main()
{
    vector<vector<char>> sudokuBoard = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    if (solveSudoku(sudokuBoard, 0, 0))
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << sudokuBoard[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists." << endl;
    }

    return 0;
}
