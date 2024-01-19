#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int value; 
    struct tree* ptr;
};

void linked_list_traversal(struct tree* head){
    while (head != NULL)
    {
        printf("%d\n", head->value); 
        head = head->ptr; 
    }
}

struct tree* deleting_first(struct tree* head){
    head = head->ptr; 
    return head; 
}

struct tree* deleting_in_between(struct tree* head, int pos){
    int counter = 2; 
    struct tree* temp = head;
    if (pos == 1)
    {
        return deleting_first(temp); 
    }
    else
        while (head!=NULL && counter != pos)
        {
            head = head->ptr; 
            counter++; 
        }
        head->ptr = head->ptr->ptr; 
        return temp; 
}

struct tree* deleting_in_end(struct tree* head){
    struct tree* orignal_head = head; 
    while (head->ptr!= NULL)
    {
        head = head->ptr;
    }
    struct tree* temp = head;
    head->ptr = NULL; 
    free(temp); 
    return orignal_head; 
}


int main(){
    struct tree* head = (struct tree*)malloc(sizeof(struct tree)); 
    struct tree* second = (struct tree*)malloc(sizeof(struct tree)); 
    struct tree* third = (struct tree*)malloc(sizeof(struct tree)); 
    head->value = 10;
    head->ptr = second; 
    second->value = 11; 
    second->ptr = third; 
    third->value = 12; 
    third->ptr = NULL; 
    // struct node* newhead = deleting_in_between(head, 3); 
    struct tree * newhead = deleting_in_end(head); 
    linked_list_traversal(newhead); 
    return 0;
}