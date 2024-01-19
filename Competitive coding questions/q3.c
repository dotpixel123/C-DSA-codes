#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    int tc;
    scanf("%d", &tc);
    int triCount[tc];
    for (int i = 0; i < tc; i++)
    {
        int j = 0;
        int n;
        scanf("%d", &n);
        int arr[n];
        int lenArr[n];
        char temp;
        do
        {
            scanf("%d%c", &arr[j], &temp);
            j++;
        } while (temp != '\n');

        for (j = 0; j < n; j++)
        {
            lenArr[j] = pow(2, arr[j]);
        }

        int triangle = 0;
        for (int j = 0; j < n - 2; j++)
        {
            int s1 = lenArr[j];
            for (int k = j + 1; k < n - 1; k++)
            {
                int s2 = lenArr[k];

                for (int l = k + 1; l < n; l++)
                {
                    int s3 = lenArr[l];
                    if (s1 + s2 > s3 && s2 + s3 > s1 && s1 + s3 > s2)
                    {
                        triangle++;
                    }
                }
            }
        }
        triCount[i] = triangle;
    }

    for (int i = 0; i < tc; i++)
    {
        printf("%d\n", triCount[i]);
    }

    return 0;
}