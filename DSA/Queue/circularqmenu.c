#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct q
{
    int size;
    int *arr;
    int f;
    int r;
} queue;

int isFull(queue *q)
{
    if (q->f == (q->r + 1) % q->size)
    {
        return 1;
    }
    return 0;
}

int isEmpty(queue *q)
{
    if (q->f == -1)
    {
        return 1;
    }
    return 0;
}

void enqueue(queue *q, int val)
{
    if (isFull(q))
    {
        printf("The queue is full\n");
    }
    else
    {
        if (q->f == -1)
        {
            q->f = 0;
        }

        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
    }
}

void dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("The queue is empty\n");
        q->r = q->f = -1;
    }
    else
    {
        q->f = (q->f + 1) % q->size;
    }
}

void traverse(queue *q)
{
    printf("Printing queue\n");
    if (isEmpty(q))
    {
        printf("Empty queue\n");
        q->f = q->r = -1;
    }
    else
    {
        for (int i = q->f; i != q->r; i = (i + 1) % q->size)
        {
            printf("%d ", q->arr[i]);
        }
        printf("%d\n", q->arr[q->r]);
    }
}

int main()
{
    int command = 0;
    queue *q = (queue *)malloc(sizeof(queue));
    q->size = 5;
    q->arr = (int *)malloc(q->size * sizeof(int));
    q->f = -1;
    q->r = -1;
    while (command != 6)
    {
        printf("Enter command\n");
        scanf("%d", &command);
        switch (command)
        {
        case 1:
            int val;
            printf("Enter the value to enqueue\n");
            scanf("%d", &val);
            enqueue(q, val);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            if (isEmpty(q))
                printf("Queue is empty\n");
            else
                printf("Queue is not empty\n");
            break;
        case 4:
            if (isFull(q))
                printf("Queue is full\n");
            else
                printf("Queue is not full\n");
            break;
        case 5:
            traverse(q);
            break;
        case 6:
            printf("Quitting\n");
            break;
        default:
            printf("Enter correct command\n");
            break;
        }
    }
    free(q->arr);
    free(q);
    return 0;
}