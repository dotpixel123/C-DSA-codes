#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tranpose(int sp1[8][3])
{
    int sp2[8][3];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            sp2[i][j] = 0;
        }
    }

    sp2[0][0] = sp1[0][1];
    sp2[0][1] = sp1[0][0];
    sp2[0][2] = sp1[0][2];


    int terms = sp1[0][2];
    int k = 1;
    for (int i = 0; i < 8; i++)
    {
        printf("%d %d %d\n", sp1[i][0], sp1[i][1], sp1[i][2]);
    }
    printf("printing transpose\n");

    for (int i = 0; i < sp1[0][1]; i++)
    {
        for (int j = 1; j <= terms; j++)
        {
            if (sp1[j][1] == i)
            {
                sp2[k][0] = sp1[j][1];
                sp2[k][1] = sp1[j][0];
                sp2[k][2] = sp1[j][2];
                k++;
            }
        }
    }
    // for (int i = 0; i < k; i++)
    // {
    //     printf("%d %d %d\n", sp2[i][0], sp2[i][1], sp2[i][2]);
    // }
}

int main()
{
    int smat[][5] = {
        {0, 0, 3, 0, 4},
        {9, 0, 5, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 2, 6, 0, 0}};

    int arr[8][3];
    arr[0][0] = 4;
    arr[0][1] = 5;
    arr[0][2] = 8;
    int index = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (smat[i][j] != 0)
            {
                arr[index][0] = i;
                arr[index][1] = j;
                arr[index][2] = smat[i][j];
                index++;
            }
        }
    }

    tranpose(arr);
    return 0;
}