#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(int n, int m, int arr[][n])
{
    int zeroCount = 0, nonzeroCount = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
                zeroCount++;
            else
                nonzeroCount++;
        }
    }
    if (zeroCount > nonzeroCount)
    {
        return 1;
    }
    return 0;
}

void display(int n, int m, int arr[][n])
{
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                count++;
            }
        }
    }
    printf("%d %d %d\n", m, n, count);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                printf("%d %d %d\n", i, j, arr[i][j]);
            }
        }
    }
}

int main()
{
    int m, n;
    printf("Enter value of m and n\n");
    scanf("%d %d", &m, &n);
    int arr[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter %d row, %d col value\n", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }
    if (check(n, m, arr))
    {
        display(n, m, arr);
    }
    return 0;
}