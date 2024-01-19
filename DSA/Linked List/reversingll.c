#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int data;
    struct tree *next;
};

struct tree *create_node(struct tree *head)
{
    int n;
    printf("Enter the node's data\n");
    scanf("%d", &n);
    struct tree *new_node = (struct tree *)malloc(sizeof(struct tree));
    struct tree *temp = head;
    while (head->next != NULL)
    {
        head = head->next;
    }
    new_node->data = n;
    head->next = new_node;
    new_node->next = NULL;
    return temp;
}


// struct node *reverse_ll(struct node *head)
// {
//     struct node *prev = NULL;
//     struct node *curr = head;
//     while (curr != NULL)
//     {
//         struct node* nxt = curr->next; 
//         curr->next = prev; 
//         prev = curr; 
//         curr = nxt; 
//     }
//     return prev; 
// }

struct tree * reversell(struct tree * head){
    struct tree* curr = head; 
    struct tree* prev = NULL; 
    while (curr != NULL)
    {
        struct tree * nextNode = curr->next; 
        curr->next = prev; 
        prev = curr; 
        curr = nextNode; 
    }
    struct tree* newHead = prev; 
    return newHead; 
}

void linked_list_traversal(struct tree *head)
{
    printf("Traversing the reversed linked list\n");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    struct tree *head = (struct tree *)malloc(sizeof(struct tree));
    head->data = 10;
    head->next = NULL;
    struct tree *newhead = create_node(create_node(create_node(head)));
    // struct node *newhead = create_node(head);
    // newhead = create_node(newhead);
    // newhead = create_node(newhead);
    struct tree* reversehead = reversell(newhead);
    linked_list_traversal(reversehead);
    return 0;
}