#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int patternMatch(char *string, char *substr)
{
    int lenSub = strlen(substr);
    for (int i = 0; string[i + lenSub - 1] != '\0'; i++)
    {
        printf("i = %c\n", string[i]);
        int isMatch = 0;
        if (string[i] == substr[0])
        {
            isMatch = 1; 
            for (int j = 1; j < lenSub; j++)
            {
                if (string[i + j] == substr[j])
                {
                    isMatch = 1;
                }
                else
                {
                    isMatch = 0;
                    break;
                }
            }
        }

        if (isMatch)
            return 1;
    }
    return 0;
}

// int patternMatch(char *string, char *substr)
// {
//     printf("%s\n", substr);
//     int lenSub = strlen(substr);
//     for (int i = 0; string[i + lenSub - 1] != '\0'; i++)
//     {
//         int count = 0;
//         printf("%c\n", string++);
// // printf("i = %c j = %c and count = %d\n", string[i], substr[i], count);
// if (substr++ == string++)
// {
//     count++;
//     if (count == lenSub)
//     {
//         printf("1\n");
//     }
// }
// else if (substr++ != string++)
// {
//     substr--;
//     count = 0;
// }
//     }
//     return 0;
// }

int main()
{
    char *myString = "This is a string";
    char *subString = "i";
    if (patternMatch(myString, subString))
    {
        printf("The string matches");
    }
    else
        printf("The string doesn't match\n");
    return 0;
}