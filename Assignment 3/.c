#include <stdio.h>

void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);

int main()
{
    int arr[100], n, i, ch;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\n1) Bubble Sort");
    printf("\n2) Selection Sort");
    printf("\n3) Insertion Sort");
    printf("\n4) Quick Sort");
    printf("\n5) Merge Sort");

    printf("\nEnter your choice: ");
    scanf("%d", &ch);

    switch(ch)
    {
        case 1:
            bubbleSort(arr, n);
            break;

        case 2:
            selectionSort(arr, n);
            break;

        case 3:
            insertionSort(arr, n);
            break;

        case 4:
            quickSort(arr, 0, n - 1);
            break;

        case 5:
            mergeSort(arr, 0, n - 1);
            break;

        default:
            printf("Invalid choice");
            return 0;
    }

    printf("Sorted array: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void bubbleSort(int arr[], int n)
{
    int i, j, temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, min, temp;

    for(i = 0; i < n - 1; i++)
    {
        min = i;

        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void insertionSort(int arr[], int n)
{
    int i, j, key;

    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void quickSort(int arr[], int low, int high)
{
    int i, j, pivot, temp, p;

    if(low < high)
    {
        pivot = arr[high];
        i = low - 1;

        for(j = low; j < high; j++)
        {
            if(arr[j] < pivot)
            {
                i++;

                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        p = i + 1;

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

void merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    int temp[100];

    i = low;
    j = mid + 1;
    k = low;

    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    while(i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}
