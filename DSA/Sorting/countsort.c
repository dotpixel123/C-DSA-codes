#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *countSort(int *arr, int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int *auxArr = (int *)calloc(max + 1, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        int ind = arr[i]; 
        auxArr[ind]++; 
    }
    
    int *sortArr = (int*)malloc(n * sizeof(int)); 
    // int ind = 0; 
    // for (int i = 0; i <= max; i++)
    // {
    //     while (auxArr[i] != 0)
    //     {
    //         sortArr[ind++] = i; 
    //         auxArr[i]--; 
    //     }
        
    // }
    int i = 0, j = 0; 
    while (j <= max)
    {
        if (auxArr[j] > 0)
        {
            sortArr[i++] = j; 
            auxArr[j]--; 
        }
        else{
            j++; 
        }
    }
    

    return sortArr;
}

int main()
{
    int *arr = (int *)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        printf("Enter %dth element: ", i);
        scanf("%d", &arr[i]);
    }
    int * sortArr = countSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", sortArr[i]);
    }
    return 0;
}