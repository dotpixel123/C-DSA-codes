#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree
{
    char info;
    struct tree *left;
    struct tree *right;
} tree;

typedef struct node
{
    char data;
    struct node *next;
} stack;

int isEmpty(stack *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

void push(stack *top, stack *c)
{
    if (top == NULL)
    {
        top = c;
        top->next = NULL;
        return;
    }
    c->next = top;
    top = c;
}

char pop(stack *top)
{
    if (isEmpty(top))
    {
        printf("Stack underflow\n");
        return NULL;
    }
    char item = top->data;
    top = top->next;
    return item;
}

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

tree *expTree(char *exp)
{
    tree *root = NULL;
    stack *s = NULL;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        printf("exp[i] = %c\n", exp[i]);
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '*')
        {
            tree *newNode = createNode(exp[i]);
            newNode->right = createNode(pop(s));
            newNode->left = createNode(pop(s));
            root = newNode;
        }
        push(s, createNode(exp[i]));
    }
    return root;
}

int main()
{
    char *postfixExp = "ab+c*";
    tree *root = expTree(postfixExp);
    inorder(root);
    return 0;
}