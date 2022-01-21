#include <bits/stdc++.h>

using namespace std;

void printBoard(int board[][20], int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool canPlace(int n, int board[][20], int x, int y)
{

    // check column
    for (int k = 0; k < x; k++)
    {
        if (board[k][y] == 1)
        {
            return false;
        }
    }

    // check top left diagonal
    int i = x;
    int j = y;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }

    // check top right diagonal
    i = x;
    j = y;
    while (i >= 0 && j < n)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j++;
    }

    return true;
}

int solveNQueen(int n, int board[][20], int i)
{
    // base case
    if (i == n)
    {
        // print the board
        printBoard(board, n);
        return 1;
    }

    // rec case
    // try to place a queen in every row
    int ways=0;
    for (int j = 0; j < n; j++)
    {

        // check whether current index is safe or not
        if (canPlace(n, board, i, j))
        {
            board[i][j] = 1;
            ways  += solveNQueen(n, board, i + 1);
            // backtrack
            //  queen not at correct position
            board[i][j] = 0;
        }
    }

    return ways;
}

int main()
{

    int board[20][20] = {0};

    cout << solveNQueen(4, board, 0);

    return 0;
}