#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int area[n];
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        int X[4];
        int Y[4];
        for (int i = 0; i < 4; i++)
        {
            scanf("%d %d", &X[i], &Y[i]);
        }
        int side = 1;
        for (int j = 0; j < 4; j++)
        {
            if (X[i] == X[j])
            {
                side = Y[j] - Y[i];
            }
        }
        area[index] = side * side;
        index++;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", area[i]);
    }

    return 0;
}