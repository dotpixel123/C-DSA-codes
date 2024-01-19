#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree
{
    int data;
    struct tree *next;
} queue;

queue *f = NULL, *r = NULL;

int isEmpty()
{
    if (f == NULL)
    {
        return 1;
    }
    return 0;
}

void enqueue(int val)
{
    queue *new = (queue *)malloc(sizeof(queue));
    new->data = val;
    new->next = NULL;
    if (f == NULL && r == NULL)
    {
        r = f = new;
    }
    else
    {
        r->next = new;
        r = new;
    }
}

void dequeue()
{
    if (isEmpty(f))
    {
        printf("The queue is empty\n");
    }
    f = f->next;
}

void traverse()
{
    if (isEmpty(f))
    {
        printf("The queue is empty\n");
        return;
    }
    struct tree *temp;
    temp = f;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n"); 
}

int main()
{
    int command = 0;
    while (command != 4)
    {
        printf("Enter command\n");
        scanf("%d", &command);
        switch (command)
        {
        case 1:
            int val;
            printf("Enter the value to enqueue\n");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            traverse();
            break;
        case 4:
            printf("Quitting\n");
            break;
        default:
            printf("Enter correct command\n");
            break;
        }
    }
    return 0;
}