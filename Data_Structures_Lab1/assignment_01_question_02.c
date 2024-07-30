//  Find the median in the unsorted array of integers.

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
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    if (n % 2 == 0)
    {
        printf(" Median: %0.2f", (float)(arr[n / 2] + arr[(n / 2) - 1]) / 2.0);
    }
    else
    {
        printf("Median: %0.2f", (float)arr[(n / 2)]);
    }
    return 0;
}
