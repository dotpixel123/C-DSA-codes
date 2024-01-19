#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}

int push(struct stack *s, char character)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->arr[++(s->top)] = character;
    }
    return 0;
}

char pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow \n ");
    }
    else
    {
        return s->arr[(s->top)--];
    }
}

int operatorPrecedence(char operator)
{
    switch (operator)
    {
    case '+':
    case '-':
        return 1;
    case '/':
    case '*':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

char *postfixConversion(char *exp)
{
    int len = strlen(exp);
    struct stack *stck = (struct stack *)malloc(sizeof(struct stack));
    stck->size = len;
    stck->top = -1;
    stck->arr = (char *)malloc(len);
    char *postfixExp = (char *)malloc(len + 1);
    int postfixIndex = 0;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '*' || exp[i] == '^')
        {
            if ((operatorPrecedence(exp[i]) <= operatorPrecedence(stck->arr[stck->top])))
            {
                char op = pop(stck);
                postfixExp[postfixIndex++] = op;
            }
            postfixExp[postfixIndex] = '\0';
            push(stck, exp[i]);
        }
        else if (exp[i] != '+' && exp[i] != '-' && exp[i] != '/' && exp[i] != '*' && exp[i] != '^')
        {
            postfixExp[postfixIndex++] = exp[i];
        }
        postfixExp[postfixIndex] = '\0';
    }
    while (!isEmpty(stck))
    {
        char op = pop(stck);
        postfixExp[postfixIndex++] = op;
    }
    postfixExp[postfixIndex] = '\0';
    free(stck->arr);
    free(stck);
    return postfixExp;
}

int main()
{
    char *exp = "a*b/c+d";
    char *postfixExp = postfixConversion(exp);
    printf("%s", postfixExp);
    // int n;
    // printf("Enter the length of string\n");
    // scanf("%d", &n);
    // getchar();
    // char *exp = (char* ) malloc(n+1);
    // printf("Enter the expression\n");
    // fgets(exp, n+1, stdin);
    // char *postfixExp = postfixConversion(exp);
    // printf("%s", postfixExp);
    // free(postfixExp);
    return 0;
}