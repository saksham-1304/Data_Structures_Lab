// Write a  program to find the minimum and maximum element in a given array

#include <stdio.h>
int main()
{
    printf("Enter the size of array: ");
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("Array Elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}