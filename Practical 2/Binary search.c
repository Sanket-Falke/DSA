#include <stdio.h>
int binarySearch(int a[], int size, int element)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == element)
        {
            return mid;
        }
        if (a[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int size;
    printf("Enter size of an array:");
    scanf("%d", &size);
    printf("Enter array elements of size %d\n", size);
    int a[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    int element;
    printf("enter the element that you want to search:");
    scanf("%d", &element);
    int indsearch = binarySearch(a, size, element);
    if (indsearch != -1)
    {
        printf("The Element %d is found at index %d", element, indsearch);
    }
    else
    {
        printf("something went wrong");
    }

    return 0;
}






