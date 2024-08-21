// Sum of Elements Of Array Using Recurssion

#include <stdio.h>
int sum_recursive(int arr[], int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else
    {
        return arr[n - 1] + sum_recursive(arr, n - 1);
    }
}
int main()
{
    int arr[] = {5, 10, 15, 20, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = sum_recursive(arr, size);
    printf("Sum of array elements: %d\n", result);
    return 0;
}
