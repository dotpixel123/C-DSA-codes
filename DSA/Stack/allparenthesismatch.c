#include <stdio.h>
#include <stdlib.h>
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

char push(struct stack *s, char value)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->arr[++(s->top)] = value;
    }
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

int isMatch(char a, char b){
    if (a == '(' && b == ')')
        return 1;
    else if (a == '{' && b == '}')
        return 1;
    else if (a == '[' && b == ']')
        return 1;
    return 0; 
}

int parenthesisMatch(char *exp)
{
    struct stack *stk = (struct stack *)malloc(sizeof(struct stack));
    stk->size = 100;
    stk->top = -1;
    stk->arr = (char *)malloc(stk->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(stk, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(stk))
            { 
                return 0;
            }
            else if (isMatch(stk->arr[stk->top], exp[i]))
            {
                pop(stk);
            }
            else
                return 0; 
        }
    }
    if (isEmpty(stk))
        return 1;
    
    return 0;
}

int main()
{
    char *exp = "8()([])";
    if (parenthesisMatch(exp))
    {
        printf("The parenthesis are matching");
    }
    else
    {
        printf("The parenthesis are not matching");
    }
    return 0;
}