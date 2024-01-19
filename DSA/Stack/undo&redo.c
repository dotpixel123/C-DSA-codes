#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int size_80;
    int top_80;
    char *arr_80[100];
} stack;

int isEmpty(stack *s)
{
    if (s->top_80 == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(stack *s)
{
    if (s->top_80 == s->size_80 - 1)
    {
        return 1;
    }
    return 0;
}

char *pop(stack *s)
{
    char *string_80 = (char *)malloc(100 * sizeof(char));
    if (isEmpty(s))
    {
        printf("Stack Underflow \n ");
    }
    else
    {
        strcpy(string_80, s->arr_80[s->top_80]);
        free(s->arr_80[s->top_80]);
        s->top_80--;
    }
    return string_80;
}

int push(stack *s, char *string_80)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->top_80++;
        s->arr_80[s->top_80] = (char *)malloc(100 * sizeof(char));

        strcpy(s->arr_80[s->top_80], string_80);
    }
    return 0;
}

void append(char doc_80[], char text_80[])
{
    int text_length = strlen(text_80);
    if (text_80[text_length - 1] == '\n')
    {
        text_80[text_length - 1] = '\0';
    }
    strcat(doc_80, text_80);
}

char *delete(char doc_80[], int len)
{
    char *delText = (char *)malloc(100 * sizeof(char));
    int doc_len = strlen(doc_80);

    if (len >= doc_len)
    {
        doc_80[0] = '\0';
        return doc_80;
    }
    strncpy(delText, doc_80 + (doc_len - len), len);
    delText[len] = '\0';
    doc_80[doc_len - len] = '\0';
    return delText;
}

void undo(char *doc_80, stack *u, stack *r)
{
    if (u->top_80 <= 0)
    {
        printf("Nothing to undo!\n");
        return;
    }
    char *text_80 = pop(u);
    push(r, text_80);
    strcpy(doc_80, u->arr_80[u->top_80]);
    free(text_80);
    return;
}

void redo(char *doc_80, stack *u, stack *r)
{
    if (r->top_80 < 0)
    {
        printf("Nothing to redo!\n");
        return;
    }
    char *text_80 = pop(r);
    push(u, text_80);
    strcpy(doc_80, u->arr_80[u->top_80]);
    free(text_80);
    return;
}

int main()
{
    char document_80[100];

    stack *ustck_80 = (stack *)malloc(sizeof(stack));
    stack *rstck_80 = (stack *)malloc(sizeof(stack));

    ustck_80->top_80 = -1;
    ustck_80->size_80 = 100;

    rstck_80->top_80 = -1;
    rstck_80->size_80 = 100;

    int command = 0;
    do
    {
        if (command == 0)
        {
            push(ustck_80, "");
            printf("Enter the document: ");
            fgets(document_80, 1000, stdin);
            int doc_length = strlen(document_80);
            if (document_80[doc_length - 1] == '\n')
            {
                document_80[doc_length - 1] = '\0';
            }
            push(ustck_80, document_80);
        }
        printf("\nCurrent Text: %s\n\n", document_80);

        printf("Enter a command: \n");
        printf("1. Add something\n");
        printf("2. Delete something\n");
        printf("3. Undo\n");
        printf("4. Redo\n");
        printf("5. Quit\n");

        scanf("%d", &command);
        getchar();
        switch (command)
        {
        case 1:
            char appendText[100];
            printf("Enter the text: ");
            fgets(appendText, 100, stdin);
            append(document_80, appendText);
            push(ustck_80, document_80);
            while (!isEmpty(rstck_80))
            {
                pop(rstck_80);
            }

            break;
        case 2:
            int length;
            printf("Enter the length you want to delete: ");
            scanf("%d", &length);
            getchar();
            delete (document_80, length);
            push(ustck_80, document_80);
            while (!isEmpty(rstck_80))
            {
                pop(rstck_80);
            }
            break;
        case 3:
            printf("Undoing the last operation\n");
            undo(document_80, ustck_80, rstck_80);
            break;
        case 4:
            printf("Redoing the last operation\n");
            redo(document_80, ustck_80, rstck_80);
            break;
        case 5:
            printf("Quitting\n");
            break;
        default:
            printf("Invalid command\n");
            break;
        }

    } while (command != 5);
    free(ustck_80);
    free(rstck_80);
    return 0;
}