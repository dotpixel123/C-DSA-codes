#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int *arr;
    int top;
    int size;
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

int pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
    }
    else
        return s->arr[(s->top)--];
}

void push(struct stack *s, int val)
{
    if (isFull(s))
    {
        printf("Stack overflow\n");
    }
    else
        s->arr[++(s->top)] = val;
}

void traverse(struct stack *s)
{
    int ind = s->top;
    while (ind >= 0)
    {
        printf("%d ", s->arr[ind]);
        ind--;
    }
    printf("\n");
}

int main()
{
    struct stack *s1 = (struct stack *)malloc(sizeof(struct stack));
    s1->size = 2;
    s1->arr = (int *)malloc(100 * sizeof(int));
    s1->top = -1;
    int command;
    while (-1)
    {
        printf("Main Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. isEmpty\n");
        printf("4. isFull\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
        printf("Enter choice\n");
        scanf("%d", &command);
        switch (command)
        {
        case 1:
            int val;
            printf("Enter the value to push into stack\n");
            scanf("%d", &val);
            push(s1, val);
            break;
        case 2:
            val = pop(s1);
            printf("popped value = %d\n", val);
            break;
        case 3:
            if (!isEmpty(s1))
            {
                printf("The stack is not empty\n");
            }
            else
                printf("Stack is empty\n");
            break;
        case 4:
            if (!isFull(s1))
            {
                printf("The stack is not full\n");
            }
            else
                printf("Stack is full\n");
            break;
        case 5:
            traverse(s1);
            break;
        case 6:
            printf("Exiting\n");
            return 0;
        default:
            printf("Enter correct command\n");
            break;
        }
    }

    return 0;
}