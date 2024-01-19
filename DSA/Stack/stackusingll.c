#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} stack;

stack *top = NULL;

int isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

void push(int val)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->data = val;
    if (top == NULL)
    {
        top = s;
        top->next = NULL;
    }
    else
    {
        s->next = top;
        top = s;
    }
}

int pop()
{
    if (isEmpty() == 1)
    {
        printf("Stack underflow\n");
        return -999;
    }

    stack *temp = top;
    int item = top->data;
    top = top->next;
    free(temp);
    return item;
}

void display()
{
    stack *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice;
    while (choice != 5)
    {
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            int val;
            printf("Enter the value to be pushed\n");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            if (isEmpty())
                printf("Stack is empty\n");
            else
                printf("Stack is not empty\n");
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Quitting\n");
            break;

        default:
            printf("Enter correct choice\n");
            break;
        }
    }

    return 0;
}