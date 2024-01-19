#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int value;
    struct tree *next;
} tree;

tree *user_input_ll()
{
    int data;
    tree *new_node = (tree *)malloc(sizeof(tree));
    printf("Enter the data\n");
    scanf("%d", &data);
    new_node->value = data;
    new_node->next = NULL;
    tree *head = new_node;
    int choice;
    do
    {
        printf("Enter choice\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            tree *next_node = (tree *)malloc(sizeof(tree));
            printf("Enter the data\n");
            scanf("%d", &data);
            new_node->next = next_node;
            next_node->value = data;
            next_node->next = NULL;
            new_node = next_node;
        }
        else if (choice >= 2)
            printf("Invalid input\n");

    } while (choice != 0);
    return head;
}

struct tree *deleteOdd(struct tree *head)
{
    struct tree *temp = head;

    while (temp->next != NULL)
    {
        if (head->value % 2 == 1)
        {
            printf("head data = %d\n", head->value);
            head = head->next;
            printf("newhead data = %d\n", head->value);
            temp = head;
        }
        else if (temp->next->value % 2 == 1)
        {
            struct tree *delNode = temp->next;
            temp->next = delNode->next;
            free(delNode);
        }
        else
            temp = temp->next;
    }
    return head;
}

void deleteHead(struct tree * head){
    head = head->next->next; 
    free(head);
    free(head->next);
    return; 
}

struct tree *deletedOdd2(struct tree *head)
{
    struct tree *temp1 = head;
    struct tree *temp2 = NULL;
    while (temp1 != NULL)
    {
        if (temp1->value % 2 == 1)
        {
            if (temp2 == NULL)
            {
                head = temp1->next;
            }
            else
            {
                struct tree *delNode = temp2->next;
                temp2->next = delNode->next;
                free(delNode);
            }
        }
        else
        {
            temp2 = temp2->next;
            temp1 = temp2->next;
        }
    }
    return head;
}

void linked_list_traversal(struct tree *head)
{
    printf("Printing value ");
    while (head != NULL)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    tree *head = user_input_ll();
    linked_list_traversal(head);
    deleteHead(head); 
    linked_list_traversal(head);
    return 0;
}