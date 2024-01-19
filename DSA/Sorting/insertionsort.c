#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int num = arr[i];
        int j = i - 1;
        while (num < arr[j] && j >= 0)
        {
            for (int k = 0; k < n; k++)
            {
                printf("%d ", arr[k]);
            }
            printf("\n");
            arr[j + 1] = arr[j];
            j--;
            printf("%d iteration\n", i);
            for (int k = 0; k < n; k++)
            {
                printf("%d ", arr[k]);
            }
            printf("\n");
        }
        arr[j + 1] = num;
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
    insertionSort(arr, 5);
    for (int k = 0; k < 5; k++)
    {
        printf("%d ", arr[k]);
    }
    return 0;
}