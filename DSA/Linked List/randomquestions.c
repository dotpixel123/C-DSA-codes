#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int data;
    struct tree *next;
};

// To find median of linkedlist WITHOUT a counter
struct tree *median(struct tree *head)
{
    struct tree *ptr1 = head;
    struct tree *ptr2 = head;
    while (ptr2->next != NULL && ptr2 != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
        if (ptr2 == NULL || ptr2->next == NULL)
        {
            return ptr1;
        }
    }
}

// To find the nth node from behind without a counter
struct tree *nth_node(struct tree *head, int n)
{
    struct tree *ptr1 = head;
    struct tree *ptr_n = head;
    for (int i = 0; i < n; i++)
    {
        ptr_n = ptr_n->next;
    }
    while (ptr_n != NULL)
    {
        ptr_n = ptr_n->next;
        ptr1 = ptr1->next;
    }
    return ptr1;
}

// To remove duplicates from linked list
struct tree *remove_duplicate(struct tree *head)
{
    struct tree *temp = head;
    struct tree *ptr1 = head;
    struct tree *ptr2 = head;
    while (ptr1 != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (ptr1->data == ptr2->next->data)
            {
                struct tree* temp2 = ptr2; 
                temp2->next = ptr2->next->next;  
            }
            else 
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return temp;
}

void linked_list_traversal(struct tree* head){
    printf("Printing linked list\n"); 
    while(head != NULL) {
        printf("%d\n", head->data); 
        head = head->next; 
    }
}

int main()
{
    struct tree *head = (struct tree *)malloc(sizeof(struct tree));
    struct tree *second = (struct tree *)malloc(sizeof(struct tree));
    struct tree *third = (struct tree *)malloc(sizeof(struct tree));
    struct tree *fourth = (struct tree *)malloc(sizeof(struct tree));
    struct tree *fifth = (struct tree *)malloc(sizeof(struct tree));
    struct tree *sixth = (struct tree *)malloc(sizeof(struct tree));

    head->data = 10;
    head->next = second;
    second->data = 11;
    second->next = third;
    third->data = 12;
    third->next = fourth;
    fourth->data = 13;
    fourth->next = fifth;
    fifth->data = 14;
    fifth->next = sixth;
    sixth->data = 15;
    sixth->next = NULL;
    struct tree *med = median(head);
    struct tree *n_node = nth_node(head, 5);
    struct tree *new_head = remove_duplicate(head);
    linked_list_traversal(new_head); 
    return 0;
}
