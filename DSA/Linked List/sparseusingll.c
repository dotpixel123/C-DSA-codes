#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int row;
    int col;
    int val;
    struct tree *next;
};

struct tree *createSparse()
{
    int i, j, m, n;
    int counter = 0, k = 0;

    printf("Enter the number of rows in matrix: ");
    scanf("%d", &n);
    printf("Enter the number of columns in matrix: ");
    scanf("%d", &m);

    int array[n][m];
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
    struct tree *header = (struct tree *)malloc(sizeof(struct tree));
    header->row = n;
    header->col = m;
    header->val = counter;
    header->next = NULL;
    struct tree *curr = NULL;
    curr = header;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (array[i][j] != 0)
            {
                struct tree *newNode = (struct tree *)malloc(sizeof(struct tree));
                newNode->next = NULL;
                newNode->row = i;
                newNode->col = j;
                newNode->val = array[i][j];
                curr->next = newNode;
                curr = newNode;
            }
        }
    }

    return header;
}

void traversal(struct tree *head)
{
    printf("Printing sparse matrix\n");
    while (head != NULL)
    {
        printf("%d\t%d\t%d\n", head->row, head->col, head->val);
        head = head->next;
    }
}

int main()
{
    struct tree *head = createSparse();

    traversal(head);
    return 0;
}