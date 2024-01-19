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

void preorder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// int leafCount(node *root)
// {
//     if (root->left == NULL && root->right == NULL)
//     {
//         printf("Returning 1\n"); 
//         return 1;
//     }
//     printf("%d ", root->data);
//     int sum = leafCount(root->left) + leafCount(root->right);
//     return sum;
// }

int leafCount(tree *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    int sum = leafCount(root->left) + leafCount(root->right);
    return sum;
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
    r2->right = r3;

    // preorder(root);
    // printf("\n");
    // inorder(root);
    // printf("\n");
    // postorder(root);

    printf("leaf count = %d\n", leafCount(root)); 

    return 0;
}