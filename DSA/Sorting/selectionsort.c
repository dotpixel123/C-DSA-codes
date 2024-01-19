#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int k = 0; k < n; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");
        int ind = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[ind])
            {
                ind = j;
            }
        }
        if (ind != i)
        {
            int temp = arr[i];
            arr[i] = arr[ind];
            arr[ind] = temp;
        }
        printf("%d iteration\n", i);
        for (int k = 0; k < n; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");
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
    selectionSort(arr, 5);
    for (int k = 0; k < 5; k++)
    {
        printf("%d ", arr[k]);
    }
    return 0;
}