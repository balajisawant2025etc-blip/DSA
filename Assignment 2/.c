#include <stdio.h>

int binarysearch(int arr[], int low, int high, int element)
{
    int mid;

    if(low > high)
    {
        return -1;
    }

    mid = (low + high) / 2;

    if(arr[mid] == element)
    {
        return mid;
    }

    if(arr[mid] < element)
    {
        return binarysearch(arr, mid + 1, high, element);
    }
    else
    {
        return binarysearch(arr, low, mid - 1, element);
    }
}

int main()
{
    int arr[100], n, i, element, result;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements in sorted order: ");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &element);

    result = binarysearch(arr, 0, n - 1, element);

    if(result == -1)
        printf("Element not found");
    else
        printf("Element found at position: %d", result + 1);

    return 0;
}
