#include <stdio.h>

int main()
{
    printf("Enter the size of array\n");
    int n;
    scanf("%d", &n);
    int arr[n][n];
    printf("Enter the elements of array\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int r1, r2, r3, c1, c2, c3, d1, d2;
    for (int i = 0; i < n; i++)
    {
        int r1 = arr[1][i];
        int r2 = arr[2][i];
        int r3 = arr[3][i];
        int c3 = arr[i][3];
        int c2 = arr[i][2];
        int c1 = arr[i][1];
    }
    for (int i = 0; i < n; i++)
    {
        int d1 = arr[i][i];
        int d2 = arr[1][3] + arr[2][2] + arr[3][1];
    }

    if (r1 != r2 && r2 != r3 && r3 != c1 && c1 != c2 && c2 != c3 && c3 != d1 && d1 != d2 && d2 != r1)
    {
        printf("The given square is not a magic square\n");
    }
    else
    {
        printf("The given square is a magic square\n");
    }

    return 0;
}