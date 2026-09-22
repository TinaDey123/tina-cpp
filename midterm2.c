#include <stdio.h>

void insertion_ascending(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void insertion_descending(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int key = 5;

    int middle = 9 / 2;

    printf("Original array:\n");
    display(arr, 9);

    if (arr[middle] == key)
    {
        printf("Element found at middle.\n");
        insertion_descending(arr, middle);
        insertion_descending(arr + middle + 1, 9 - middle - 1);

        printf("After sorting left and right side:\n");
        display(arr, 9);
    }
    else
    {
        printf("Element not found in middle.\n");

        printf("Sorting entire array in ascending order:\n");

        insertion_ascending(arr, 9);

        display(arr, 9);
    }

    return 0;
}
