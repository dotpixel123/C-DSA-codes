#include <stdio.h>
#include <stdlib.h>
struct tree
{
    struct tree *prev;
    int data;
    struct tree *next;
};

struct tree *user_input()
{
    int value;
    struct tree *new_node = (struct tree *)malloc(sizeof(struct tree));
    printf("Enter the data\n");
    scanf("%d", &value);
    new_node->prev = NULL;
    new_node->data = value;
    new_node->next = NULL;
    struct tree *head = new_node;
    int choice;
    do
    {
        printf("Enter choice\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            struct tree *next_node = (struct tree *)malloc(sizeof(struct tree));
            printf("Enter the data\n");
            scanf("%d", &value);
            new_node->next = next_node;
            next_node->prev = new_node;
            next_node->data = value;
            next_node->next = NULL;
            new_node = next_node;
        }
        else if (choice >= 2)
            printf("Invalid input\n");

    } while (choice != 0);
    return head;
}

void ll_traversal(struct tree *head)
{
    printf("Printing elements\n");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void reverse_ll_traversal(struct tree *head)
{
    printf("Printing elements\n");
    while (head->next != NULL)
    {
        head = head->next;
    }
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->prev;
    }
    printf("\n");
}

struct tree *insert_in_beginning(struct tree *head)
{
    struct tree *new_head = (struct tree *)malloc(sizeof(struct tree));
    printf("Enter element to be inserted in beginning of list\n");
    scanf("%d", &new_head->data);
    head->prev = new_head;
    new_head->next = head;
    new_head->prev = NULL;
    return new_head;
}

struct tree *insert_in_between(struct tree *head)
{
    int pos;
    printf("Enter the position\n");
    scanf("%d", &pos);
    struct tree *new_node = (struct tree *)malloc(sizeof(struct tree));
    int counter = 2;
    struct tree *temp = head;
    if (pos == 1)
    {
        insert_in_beginning(head);
    }
    else
    {
        while (pos != counter)
        {
            head = head->next;
            counter++;
        }
        printf("Enter the element to be inserted\n");
        scanf("%d", &new_node->data);
        new_node->prev = head;
        new_node->next = head->next;
        head->next->prev = new_node;
        head->next = new_node;
        return temp;
    }
}

struct tree *delete_first(struct tree *head)
{
    struct tree *temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    return head;
}

struct tree* delete_in_between(struct tree* head){
    struct tree* temp = head;
    int pos; 
    printf("Enter the position to be deleted\n"); 
    scanf("%d", &pos); 
    int counter = 2; 
    if (pos == 1)
    {
        delete_first(head); 
    }
    else 
        while (counter != pos)
        {
            head = head->next; 
            counter++; 
        }
        struct tree* node_to_delete = head->next; 
        head->next = node_to_delete->next; 
        head->next->prev = head;
        free(node_to_delete); 
        return temp; 
}

int main()
{
    struct tree *head = user_input();
    struct tree *newhead = insert_in_between(head);
    ll_traversal(newhead);
    reverse_ll_traversal(newhead);
    return 0;
}