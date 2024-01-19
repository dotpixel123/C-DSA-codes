#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int value; 
    struct tree* next; 
}tree;

tree* circular_ll(){
    int data;
    tree* new_node = (tree*)malloc(sizeof(tree)); 
    printf("Enter the data\n"); 
    scanf("%d", &data); 
    new_node->value = data; 
    new_node->next = NULL; 
    tree* head = new_node; 
    int choice; 
    do
    {
        printf("Enter choice\n"); 
        scanf("%d", &choice); 
        if (choice == 1)
        {
            tree* next_node = (tree*)malloc(sizeof(tree)); 
            printf("Enter the data\n"); 
            scanf("%d", &data); 
            new_node->next = next_node; 
            next_node->value = data; 
            next_node->next = head; 
            new_node = next_node; 
        }
        else if (choice >= 2)
            printf("Invalid input\n");
        
    } while (choice != 0);
    return head; 
}

void circular_linked_list_traversal(struct tree* head){
    printf("Printing value "); 
    struct tree* temp = head; 
    do {
        printf("%d ", head->value);
        head = head->next;
    } while (head != temp);
}

int main(){
    tree* head = circular_ll();
    circular_linked_list_traversal(head);
    return 0;
}