#include <stdio.h>
#include <stdlib.h>
struct tree{
    int data;
    struct tree *next; 
};

struct tree* insert_in_beginning(struct tree* head, int value){
    struct tree* new_head = (struct tree*)malloc(sizeof(struct tree)); 
    new_head->data = value; 
    new_head->next = head; 
    return new_head; 
}

struct tree* insert_in_between(struct tree*head, int pos, int value){
    struct tree* new_node = (struct tree*)malloc(sizeof(struct tree)); 
    struct tree* temp = head; 
    int counter = 2; 
    if (pos == 1)
    {
        return insert_in_beginning(head, value); 
    }
    else 
        while (counter != pos)
        {
            head = head->next; 
            counter++; 
        }
        new_node->data = value; 
        new_node->next = head->next; 
        head->next = new_node; 
        return temp; 
}

struct tree* insert_in_end(struct tree* head, int value){
    struct tree* end_node = (struct tree*) malloc(sizeof(struct tree)); 
    struct tree* temp = head; 
    while (head->next!= NULL)
    { 
        head = head->next; 
    }
    end_node->data = value;
    head->next = end_node; 
    end_node->next = NULL; 
    return temp; 
}

void insert_after_pointer(struct tree* pointer, int value){
    struct tree* new_node = (struct tree*)malloc(sizeof(struct tree)); 
    new_node->data = value; 
    new_node->next = pointer->next;
    pointer->next = new_node; 
    return; 
}

void linked_list_traversal(struct tree* head){
    while(head != NULL) {
        printf("%d\n", head->data); 
        head = head->next; 
    }
}

int main(){
    struct tree* head = (struct tree*)malloc(sizeof(struct tree)); 
    struct tree* second = (struct tree*)malloc(sizeof(struct tree)); 
    struct tree* third = (struct tree*)malloc(sizeof(struct tree)); 
    head->data = 10;
    head->next = second; 
    second->data = 11; 
    second->next = third; 
    third->data = 12; 
    third->next = NULL; 
    // struct node* new_head = insert_in_beginning(head, 9); 
    // struct node* new_head = insert_in_between(head, 4, 9);
    // struct node* new_head = insert_in_end(head, 15);
    insert_after_pointer(third, 13); 
    linked_list_traversal(head);
    return 0;
}