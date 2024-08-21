//Question 1:Take input as a Matrix and Convert it to Sparse Matrix

#include <stdio.h>
int main()
{
    int row1, col1;
    printf("Enter the number of rows and columns for first matrix\n");
    scanf("%d %d", &row1, &col1);

    // Matrix Input
    int mat1[row1][col1];
    printf("Enter the elements row-wise\n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    int row2, col2;
    printf("Enter the number of rows and columns for second matrix\n");
    scanf("%d %d", &row2, &col2);

    // Matrix Input
    int mat2[row2][col2];
    printf("Enter the elements row-wise\n");
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }

    int count1 = 0;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            if (mat1[i][j] != 0)
            {
                count1++;
            }
        }
    }

    int sparse1[count1][3];
    int k = 0;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            if (mat1[i][j] != 0)
            {
                sparse1[k][0] = i;
                sparse1[k][1] = j;
                sparse1[k][2] = mat1[i][j];
                k++;
            }
        }
    }
    int count2 = 0;
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            if (mat2[i][j] != 0)
            {
                count2++;
            }
        }
    }

    int sparse2[count2][3];
    k = 0;
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            if (mat2[i][j] != 0)
            {
                sparse2[k][0] = i;
                sparse2[k][1] = j;
                sparse2[k][2] = mat2[i][j];
                k++;
            }
        }
    }
    printf("Sparse Matrix 1\n");
    for (int i = 0; i < count1; i++)
    {
        printf("%d %d %d\n", sparse1[i][0], sparse1[i][1], sparse1[i][2]);
    }
    printf("Sparse Matrix 2\n");
    for (int i = 0; i < count2; i++)
    {
        printf("%d %d %d\n", sparse2[i][0], sparse2[i][1], sparse2[i][2]);
    }
    int sparseSum[count1 + count2][3]; // Maximum possible size
    int i = 0, j = 0, l = 0;

    //Question 2 : To Add Two Sparse Matrices


    // Traverse both sparse matrices and add corresponding elements
    while (i < count1 && j < count2)
    {
        if (sparse1[i][0] < sparse2[j][0] ||
            (sparse1[i][0] == sparse2[j][0] && sparse1[i][1] < sparse2[j][1]))
        {
            // Element of sparse1 comes first
            sparseSum[l][0] = sparse1[i][0];
            sparseSum[l][1] = sparse1[i][1];
            sparseSum[l][2] = sparse1[i][2];
            i++;
        }
        else if (sparse1[i][0] > sparse2[j][0] ||
                 (sparse1[i][0] == sparse2[j][0] && sparse1[i][1] > sparse2[j][1]))
        {
            // Element of sparse2 comes first
            sparseSum[l][0] = sparse2[j][0];
            sparseSum[l][1] = sparse2[j][1];
            sparseSum[l][2] = sparse2[j][2];
            j++;
        }
        else
        {
            // Same position in both matrices
            sparseSum[l][0] = sparse1[i][0];
            sparseSum[l][1] = sparse1[i][1];
            sparseSum[l][2] = sparse1[i][2] + sparse2[j][2];
            i++;
            j++;
        }
        l++;
    }

    // If any elements are left in sparse1
    while (i < count1)
    {
        sparseSum[l][0] = sparse1[i][0];
        sparseSum[l][1] = sparse1[i][1];
        sparseSum[l][2] = sparse1[i][2];
        i++;
        l++;
    }

    // If any elements are left in sparse2
    while (j < count2)
    {
        sparseSum[l][0] = sparse2[j][0];
        sparseSum[l][1] = sparse2[j][1];
        sparseSum[l][2] = sparse2[j][2];
        j++;
        l++;
    }

    printf("Resultant Sparse Matrix \n");
    for (int i = 0; i < l; i++)
    {
        printf("%d %d %d\n", sparseSum[i][0], sparseSum[i][1], sparseSum[i][2]);
    }

    //Question 3: To Calculate Transpose Of The Result of Array
    for (int i = 0; i < l; i++)
    {
        int temp = sparseSum[i][0];
        sparseSum[i][0] = sparseSum[i][1];
        sparseSum[i][1] = temp;
    }
    printf("Transpose Of Resultant Sparse Matrix \n");
    for (int i = 0; i < l; i++)
    {
        printf("%d %d %d\n", sparseSum[i][0], sparseSum[i][1], sparseSum[i][2]);
    }
}
