//Linear Search


#include <stdio.h>
    void
    linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            printf("The key is at %d index \n", i);
            return;
        }
    }
    printf("Key not present");
}

int main()
{
    printf("Ënter the  size of arraÿ:\n");
    int size;
    scanf("%d", &size);
    printf("Enter the elements of array:\n");
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter key you want to search:\n ");
    int key;
    scanf("%d", &key);
    linearSearch(arr, size, key);
}
