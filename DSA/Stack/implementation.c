#include <stdio.h>
#include <stdlib.h>
struct stack{
    int size; 
    int top; 
    int *arr; 
};

int isEmpty(struct stack *s){
    if (s->top == -1)
    { 
        return 1; 
    }
    return 0; 
}

int isFull(struct stack *s){
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}

int peek(struct stack *s, int n){
    if (n < 1 || n > s->top + 1)
    {
        printf("Invalid value of n\n"); 
        return -1; 
    }
    
    int element = s->arr[s->top - (n - 1)]; 
    return element;
}

void push(struct stack *s){
    if (isFull(s))
    {
        printf("The stack is full\n"); 
    }
    else{  
        printf("Enter the element to be inserted\n"); 
        s->top++; 
        scanf("%d", s->arr + (s->top)); 
        printf("Printing elements\n"); 
        for (int i = 0; i < s->size; i++)
        {
            printf("%d\n", s->arr[i]); 
        }
    }
}

int pop(struct stack * s){
    int value = s->arr[s->top];
    s->top--; 
    return value; 
}

int main(){
    struct stack *s1 = (struct stack * )malloc(sizeof(struct stack)); 
    s1->size = 10; 
    s1->top = 1; 
    s1->arr = (int *)malloc(s1->size * sizeof(int));  
    s1->arr[0] = 102; 
    s1->arr[1] = 44; 
    // if (isEmpty(s1))
    // {
    //     printf("Empty");
    // }
    // else if (isFull(s1))
    // {
    //     printf("Full"); 
    // }
    // else
    //     printf("Nothing");

    push(s1); 
    printf("%d", peek(s1, 1));
    return 0;
}