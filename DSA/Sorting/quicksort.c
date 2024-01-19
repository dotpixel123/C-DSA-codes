#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partition(int *arr, int low, int high)
{
    int i = low + 1;
    int j = high;
    int pivot = arr[low];
    int temp; 
    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

int *quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivotInd = partition(arr, low, high);
        quickSort(arr, low, pivotInd - 1);
        quickSort(arr, pivotInd + 1, high);
    }
    return arr;
}

int main()
{
    int *arr = (int *)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        printf("Enter %dth element: ", i);
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, 4);
    for (int k = 0; k < 5; k++)
    {
        printf("%d ", arr[k]);
    }
    return 0;
}