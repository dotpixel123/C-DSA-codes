#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int *arr, int low, int mid, int high)
{
    int size = high - low + 1;
    int *auxArr = (int *)malloc(size * sizeof(int));
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            auxArr[k++] = arr[i++]; 
        }
        else {
            auxArr[k++] = arr[j++]; 
        }
    }
    while (i <= mid)
    {
        auxArr[k++] = arr[i++];
    }
    while (j <= high)
    {
        auxArr[k++] = arr[j++];
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = auxArr[i];
    }
    free(auxArr);
}

void mergeSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = (high + low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int *arr = (int *)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        printf("Enter %dth element: ", i);
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, 5);
    for (int k = 0; k < 5; k++)
    {
        printf("%d ", arr[k]);
    }
    return 0;
}