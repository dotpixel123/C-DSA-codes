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

int isBST(tree *root)
{
    // printf("\n1. %d ", root->data);
    static tree *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }

        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
        return 1;
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

int iterativeSearch(tree *root, int val)
{
    while (root != NULL)
    {
        if (root->data == val)
        {
            return 1;
        }
        else if (root->data < val)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return 0; // Value not found
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
    r1->left = r2;
    r1->right = r3;

    // inorder(root);
    // if (isBST(root))
    //     printf("it is BST\n");
    // else
    //     printf("it is not BST\n");

    int ans = iterativeSearch(root, 10);
    printf("%d", ans);

    return 0;
}