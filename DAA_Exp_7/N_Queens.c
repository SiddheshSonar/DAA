#include <stdio.h>
#include <stdbool.h>

int n;

void printBoard(int board[n][n])
{
    printf("\nSolution:\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
            {
                printf(" Q ");
            }
            else
            {
                printf(" * ");
            }
        }
        printf("\n");
    }
}

bool isSafe(int board[n][n], int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    return true;
}

bool NQueen(int board[n][n], int col)
{
    if (col >= n)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            if (NQueen(board, col + 1))
            {
                return true;
            }

            board[i][col] = 0;
        }
    }
    return false;
}

int main()
{
    printf("\nEnter the number of Queens: ");
    scanf("%d", &n);
    int board[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    if (NQueen(board, 0) == false)
    {
        printf("Solution does not exist");
        return false;
    }

    printBoard(board);
    return 0;
}
