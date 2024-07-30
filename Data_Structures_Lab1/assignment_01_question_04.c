#include <stdio.h>
int main()
{
    printf("Enter the size of the square matrix: ");
    int n;
    scanf("%d", &n);
    int arr[n][n];
    printf("Enter the elements of the matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int magic_sum = 0;
    for (int i = 0; i < n; i++)
    {
        magic_sum += arr[0][i];
    }

    // Check sums of all rows
    for (int i = 1; i < n; i++)
    {
        int row_sum = 0;
        for (int j = 0; j < n; j++)
        {
            row_sum += arr[i][j];
        }
        if (row_sum != magic_sum)
        {
            printf("The given square is not a magic square\n");
            return 0;
        }
    }

    // Check sums of all columns
    for (int j = 0; j < n; j++)
    {
        int col_sum = 0;
        for (int i = 0; i < n; i++)
        {
            col_sum += arr[i][j];
        }
        if (col_sum != magic_sum)
        {
            printf("The given square is not a magic square\n");
            return 0;
        }
    }

    // Check the sum of the main diagonal
    int diag1_sum = 0;
    for (int i = 0; i < n; i++)
    {
        diag1_sum += arr[i][i];
    }
    if (diag1_sum != magic_sum)
    {
        printf("The given square is not a magic square\n");
        return 0;
    }

    // Check the sum of the secondary diagonal
    int diag2_sum = 0;
    for (int i = 0; i < n; i++)
    {
        diag2_sum += arr[i][n - 1 - i];
    }
    if (diag2_sum != magic_sum)
    {
        printf("The given square is not a magic square\n");
        return 0;
    }

    printf("The given square is a magic square\n");
    return 0;
}
