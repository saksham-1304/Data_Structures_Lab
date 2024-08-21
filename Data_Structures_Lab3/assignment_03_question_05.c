//Binary Search

#include <stdio.h>
void binarySearch(int arr[], int key, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size - i; j++)
        {

            if (arr[j - 1] > arr[j])
            {
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int s = 0;
    int e = size - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == key)
        {
            printf("Key is present\n");
            return;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    printf("Key is not present");
}
int main()
{
    printf("Enter the size of array: \n");
    int size;
    scanf("%d", &size);
    printf("Enter the elements of array: \n");
    int arr[size];
    for (int i = 0; i < size; i++)
    {

        scanf("%d", &arr[i]);
    }
    printf("Enter key you want to search: \n");
    int key;
    scanf("%d", &key);
    binarySearch(arr, key, size);
}
