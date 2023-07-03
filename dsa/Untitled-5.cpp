#include <iostream>
using namespace std;
#define n 4
void PrintBoard(int board[n][n])
{

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
            cout << board[row][col] << " ";
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int board[n][n], int row, int col)
{

    bool FlagSafe = true;
    for (int r = row - 1; r >= 0; r--) // vertically up
    {
        if (board[r][col] == 1)
        {
            return false;
        }
    }
    for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--) // left upper diagonal
    {
        if (board[r][c] == 1)
        {
            return false;
        }
    }
    for (int r = row - 1, c = col + 1; r >= 0 && c < n; r--, c++) // right upper diagonal
    {
        if (board[r][c] == 1)
        {
            return false;
        }
    }
    return FlagSafe;
}

bool nQueenUtil(int board[n][n], int row)
{

    if (row == n)
    {
        PrintBoard(board);
        // not returning true here
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {

            board[row][col] = 1;

            if (nQueenUtil(board, row + 1))
            {

                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}
int main()
{
    cout << "For " << n << " * " << n << " matrix : \n";

    int board[n][n] = {0};

    nQueenUtil(board, 0);
    return 0;
}

