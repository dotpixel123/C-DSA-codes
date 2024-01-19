#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree
{
    char info;
    struct tree *left;
    struct tree *right;
} tree;



tree *createNode(char c)
{
    tree *newNode = (tree *)malloc(sizeof(tree));
    newNode->info = c;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%c ", root->info);
    inorder(root->right);
}

int operation(char op, int a, int b)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
}

int evalExp(tree *root)
{
    if (root->right == NULL && root->left == NULL)
    {
        return root->info - '0';
    }
    return operation(root->info, evalExp(root->left), evalExp(root->right));
}

int main()
{
    tree *root = createNode('*');
    tree *op1 = createNode('+');
    tree *oprnd1 = createNode('4');
    tree *oprnd2 = createNode('2');
    tree *oprnd3 = createNode('3');

    root->left = op1;
    root->right = oprnd3;
    op1->left = oprnd1;
    op1->right = oprnd2;

    printf("The expression to evaluate is\n");
    inorder(root);
    int ans = evalExp(root);
    printf("\nAnswer is %d\n", ans); 

    char * exp = "abc*+d-";
    return 0;
}