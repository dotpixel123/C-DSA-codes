#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
} tree;

tree *createNode(int val)
{
    tree *newNode = (tree *)malloc(sizeof(tree));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main()
{
    tree *root = createNode(5);
    tree *l1 = createNode(4);
    tree *l2 = createNode(3);
    tree *l3 = createNode(2);
    tree *r1 = createNode(6);
    tree *r2 = createNode(7);
    tree *r3 = createNode(8);

    root->left = l1;
    l1->left = l2;
    l1->right = l3;
    root->right = r1;
    r1->left = r2;
    r1->right = r3;

    return 0;
}