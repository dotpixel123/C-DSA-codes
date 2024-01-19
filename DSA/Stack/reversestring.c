#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

void push(struct stack *s, char c)
{
    if (s->top == s->size)
    {
        printf("Stack overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = c;
}

char pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack underflow\n");
        return 'x';
    }
    char c = s->arr[s->top];
    s->top--;
    return c;
}

char * revString(struct stack *s, char *string)
{
    int len = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        push(s, string[i]);
        len++;
    }
    char * reverse = (char*)malloc(len * sizeof(char));
    for (int i = 0; i < len; i++)
    {
        reverse[i] = pop(s);
    }
    reverse[len] = '\0';
    return reverse;
}

int main()
{
    struct stack *stk = (struct stack *)malloc(sizeof(struct stack));
    stk->top = -1;
    stk->size = 100;
    stk->arr = (char *)malloc(stk->size * sizeof(char));
    char *myString = "Shourya";
    revString(stk, myString); 
    char *reverseString = revString(stk, myString);
    printf("%s", reverseString);
    return 0;
}