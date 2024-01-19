#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int coeff;
    int exp;
    struct tree *next;
};

struct tree *addPoly(struct tree *poly1, struct tree *poly2)
{
    struct tree *poly3 = (struct tree *)malloc(sizeof(struct tree));
    struct tree *curr = poly3;
    int count = 0;
    while (poly1 != NULL || poly2 != NULL)
    {
        struct tree *newNode = (struct tree *)malloc(sizeof(struct tree));
        newNode->next = NULL;
        if (poly1->exp > poly2->exp)
        {
            newNode->coeff = poly1->coeff;
            newNode->exp = poly1->exp;
            poly1 = poly1->next;
        }
        else if (poly1->exp < poly2->exp)
        {
            newNode->coeff = poly2->coeff;
            newNode->exp = poly2->exp;
            poly2 = poly2->next;
        }
        else if (poly1->exp == poly2->exp)
        {
            newNode->coeff = poly2->coeff + poly1->coeff;
            newNode->exp = poly2->exp;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        if (count == 0)
        {
            poly3 = newNode;
            count = 1;
        }
        else
        {
            curr->next = newNode;
        }
        curr = newNode;
    }
    while (poly1 != NULL || poly2 != NULL)
    {
        struct tree *node = (struct tree *)malloc(sizeof(struct tree));
        node->next = NULL;
        if (poly1 != NULL)
        {
            node->coeff = poly1->coeff;
            node->exp = poly1->exp;
            poly1 = poly1->next;
        }
        if (poly2 != NULL)
        {
            node->coeff = poly2->coeff;
            node->exp = poly2->exp;
            poly2 = poly2->next;
        }
        curr->next = node;
        curr = node;
    }

    return poly3;
}

struct tree *mulPoly(struct tree *poly1, struct tree *poly2)
{
    struct tree *poly3 = NULL;
    struct tree *curr = poly3;
    while (poly1 != NULL)
    {
        while (poly2 != NULL)
        {
            struct tree *newNode = (struct tree *)malloc(sizeof(struct tree));
            newNode->next = NULL;
            newNode->exp = poly1->exp + poly2->exp;
            newNode->coeff = poly1->coeff * poly2->coeff;
        }
        poly1 = poly1->next;
    }
}

struct tree *createPoly()
{
    struct tree *head = (struct tree *)malloc(sizeof(struct tree));
    struct tree *temp = head;

    int command = 1;
    int count = 0;
    while (command)
    {
        struct tree *nextNode = (struct tree *)malloc(sizeof(struct tree));
        if (count == 0)
        {
            nextNode = head;
            count = 1;
        }
        if (count == 1)
        {
            temp->next = nextNode;
        }

        printf("Enter the coefficient: ");
        scanf("%d", &nextNode->coeff);
        printf("Enter the exp: ");
        scanf("%d", &nextNode->exp);
        nextNode->next = NULL;
        temp = nextNode;
        printf("Continue?\n");
        scanf("%d", &command);
    }
    return head;
}

void traversal(struct tree *head)
{
    while (head != NULL)
    {
        printf("%d x^%d + ", head->coeff, head->exp);
        head = head->next;
    }
    printf("0\n");
}

int main()
{
    struct tree *poly1 = createPoly();
    printf("printing poly1\n");
    traversal(poly1);
    struct tree *poly2 = createPoly();
    printf("printing poly2\n");
    traversal(poly2);
    struct tree *poly3 = addPoly(poly1, poly2);
    printf("printing poly3\n");
    traversal(poly3);
    return 0;
}