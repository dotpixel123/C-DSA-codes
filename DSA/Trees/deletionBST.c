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

void inorder(tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
    return;
}

int searchBST(tree *root, int val)
{
    if (root == NULL)
    {
        return 0;
    }
    if (val < root->data)
    {
        return searchBST(root->left, val);
    }
    else if (val > root->data)
    {
        return searchBST(root->right, val);
    }
    else
    {
        return 1;
    }
}

tree *deleteBST(tree *root, int val)
{
    
}

int main()
{
    tree *root = createNode(4);
    tree *l1 = createNode(2);
    tree *l2 = createNode(1);
    tree *l3 = createNode(3);
    tree *r1 = createNode(6);
    tree *r2 = createNode(5);
    tree *r3 = createNode(7);

    root->left = l1;
    l1->left = l2;
    l1->right = l3;
    root->right = r1;
    r1->left = NULL;
    r1->right = r3;
    root = deleteBST(root, 5); 
    inorder(root); 
    return 0;
}