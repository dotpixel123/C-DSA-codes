
// Q. Write a program in C to merge two arrays.
#include <stdio.h>
#include <stdlib.h>
int *mergeArray(int arr1[], int arr2[], int n, int m)
{
    int *mergedArr = (int *)malloc(sizeof(m + n));
    for (int i = 0; i < n; i++)
    {
        mergedArr[i] = arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        mergedArr[i + n] = arr2[i];
    }
    return mergedArr;
}

int main()
{
    int arr1[4] = {1, 2, 3, 5};
    int arr2[3] = {3, 2, 1};
    int *mergedArr = mergeArray(arr1, arr2, 4, 3);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", mergedArr[i]);
    }

    return 0;
}