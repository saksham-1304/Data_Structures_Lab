//  Find the second largest element in an unsorted array.

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
    int largest = arr[0];
    int secondLargest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }

        else if (arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }
    printf("Second maximum element: %d", secondLargest);
    return 0;
}
