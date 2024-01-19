#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct tree
{
    char character;
    struct tree *next;
    struct tree *prev;
};

int palindromeCheck(struct tree *head)
{
    char *frwrdStr = (char *)malloc(sizeof(100));
    char *bckwrdStr = (char *)malloc(sizeof(100));
    int index = 0;
    while (head->next != NULL)
    {
        if (!index)
        {
            frwrdStr[0] = head->character;
        }
        head = head->next;
        index++;
        frwrdStr[index] = head->character;
    }
    frwrdStr[index + 1] = '\0';
    index = 0;
    while (head != NULL)
    {
        bckwrdStr[index] = head->character;
        head = head->prev;
        index++;
    }
    bckwrdStr[index] = '\0';
    if (!strcmp(frwrdStr, bckwrdStr))
    {
        return 1; 
    }
    return 0; 
}

void traversal(struct tree *head)
{
    printf("Printing elements\n");
    while (head != NULL)
    {
        printf("%c ", head->character);
        head = head->next;
    }
    return;
}
int main()
{
    struct tree *head = (struct tree *)malloc(sizeof(struct tree));
    struct tree *second = (struct tree *)malloc(sizeof(struct tree));
    struct tree *third = (struct tree *)malloc(sizeof(struct tree));
    head->character = 'a';
    head->next = second;
    head->prev = NULL;
    second->character = 'b';
    second->next = third;
    second->prev = head;
    third->character = 'a';
    third->next = NULL;
    third->prev = second;

    if (palindromeCheck(head))
    {
        printf("It is a palindrome\n");
    }
    else printf("It is NOT a palindrome\n");
    // traversal(head);
    return 0;
}