#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int spmatAdd(int sp1[][3], int sp2[][3], int terms)
{
    printf("terms = %d\n", terms);
    int sp3[terms + 1][3];
    for (int i = 0; i <= terms; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sp3[i][j] = 0;
        }
    }
    sp3[0][0] = sp1[0][1];
    sp3[0][1] = sp1[0][0]; 
    sp3[0][2] = sp1[0][2];

    int k = 1;
    for (int i = 1; i <= terms; i++)
    {
        for (int j = 1; j <= terms; j++)
        {
            if (sp1[i][0] == sp2[j][0] && sp1[i][1] == sp2[j][1])
            {
                sp3[k][1] = sp1[i][1];
                sp3[k][0] = sp1[i][0];
                sp3[k][2] += sp1[i][2] + sp2[i][2]; 
                k++;
            }
        }
    }

    for (int i = 0; i <= terms; i++)
    {
        printf("%d\t%d\t%d\n", sp3[i][0], sp3[i][1], sp3[i][2]);
    }
}

int main()
{
    int i, j, m, n;
    int counter = 0, k = 0;

    printf("Enter the number of rows in matrix: ");
    scanf("%d", &n);
    printf("Enter the number of columns in matrix: ");
    scanf("%d", &m);

    int **array = (int **)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        array[i] = (int *)malloc(m * sizeof(int));

    // int array[n][m];
    printf("Enter the co-efficients of the matix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("Enter the [%d][%d] element of matrix: ", i + 1, j + 1);
            scanf("%d", &array[i][j]);
            if (array[i][j] != 0)
            {
                counter++;
            }
        }
    }

    // 3 tuple format
    int tuple3[counter + 1][3];
    tuple3[k][0] = n;
    tuple3[k][1] = m;
    tuple3[k][2] = counter;
    k++;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (array[i][j] != 0)
            {
                tuple3[k][0] = i;
                tuple3[k][1] = j;
                tuple3[k][2] = array[i][j];
                k++;
            }
        }
    }

    free(array);

    printf("\n3 Tuple Matrix: \n");
    for (i = 0; i <= counter; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", tuple3[i][j]);
        }
        printf("\n");
    }

    spmatAdd(tuple3, tuple3, tuple3[0][2]);
    return 0;
}