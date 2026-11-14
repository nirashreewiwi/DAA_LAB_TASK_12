#include <stdio.h>

#define MAX 20

int board[MAX][MAX];
int n;

// Function to check whether queen can be placed safely
int isSafe(int row, int col)
{
    int i, j;

    // Check same column
    for (i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return 0;
    }

    // Check upper-left diagonal
    for (i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return 0;
    }

    // Check upper-right diagonal
    for (i = row - 1, j = col + 1;
         i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
            return 0;
    }

    return 1;
}

// Function to solve N-Queen using backtracking
int solveNQueen(int row)
{
    int col;

    // All queens have been placed
    if (row == n)
        return 1;

    // Try every column in the current row
    for (col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1;

            if (solveNQueen(row + 1))
                return 1;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return 0;
}

// Function to display the chessboard
void display()
{
    int i, j;

    printf("\nSolution:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
                printf(" Q ");
            else
                printf(" - ");
        }
        printf("\n");
    }
}

int main()
{
    int i, j;

    printf("Enter the number of queens: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid input!");
        return 0;
    }

    // Initialize the board
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    if (solveNQueen(0))
    {
        display();
    }
    else
    {
        printf("No solution exists.");
    }

    return 0;
}
