#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    int pri;
    struct node *next;
} queue;

int isEmpty(queue *f)
{
    if (f == NULL)
    {
        return 1;
    }
    return 0;
}

void enqueue(queue *f, queue *r, int val, int priority)
{
    queue *new, *temp;
    temp = f; 
    new = (queue *)malloc(sizeof(queue));
    new->data = val;
    new->pri = priority;
    if (r == NULL)
    {
        r = f = new;
        return;
    }
    while (temp->next->pri < priority)
    {
        temp = temp->next; 
    }
    queue* nextNode = temp->next;
    temp->next = new;
    new->next = nextNode;
}

int main()
{

    return 0;
}