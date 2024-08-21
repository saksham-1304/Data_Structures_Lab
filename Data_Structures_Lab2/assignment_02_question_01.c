// Find Union And Intersection Of The Given Arrays

#include <stdio.h>
void findUnion(int arr1[], int size1, int arr2[], int size2)
{
    int unionArr[size1 + size2];
    int unionSize = 0;
    for (int i = 0; i < size1; i++)
    {
        unionArr[unionSize++] = arr1[i];
    }
    for (int i = 0; i < size2; i++)
    {
        int found = 0;
        for (int j = 0; j < size1; j++)
        {
            if (arr2[i] == arr1[j])
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            unionArr[unionSize++] = arr2[i];
        }
    }
    printf("Union of arrays: ");
    for (int i = 0; i < unionSize; i++)
    {
        printf("%d ", unionArr[i]);
    }
    printf("\n");
}
void findIntersection(int arr1[], int size1, int arr2[], int size2)
{
    printf("Intersection of arrays: ");
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                printf("%d ", arr1[i]);
                break;
            }
        }
    }
    printf("\n");
}
int main()
{
    int size1, size2;
    printf("Enter the size of the first array: ");
    scanf("%d", &size1);
    int arr1[size1];
    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < size1; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the size of the second array: ");
    scanf("%d", &size2);
    int arr2[size2];
    printf("Enter the elements of the second array:\n");
    for (int i = 0; i < size2; i++)
    {
        scanf("%d", &arr2[i]);
    }
    findUnion(arr1, size1, arr2, size2);
    findIntersection(arr1, size1, arr2, size2);
    return 0;
}
