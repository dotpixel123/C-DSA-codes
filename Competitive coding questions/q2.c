#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int tc;
    scanf("%d", &tc);

    int move[tc]; 
    for (int i = 0; i < tc; i++)
    {
        int n;
        scanf("%d", &n);
        char inArray[n];
        char outArray[n];
        scanf("%s", inArray);
        scanf("%s", outArray);
        int moveCount = 0;
        int count1 = 0;
        int count2 = 0;
        for (int j = 0; j < n; j++)
        {
            if (outArray[j] == '1')
            {
                count1++;
            }
            if (inArray[j] == '1')
            {
                count2++;
            }
        }

        for (int j = 0; j < n; j++)
        {
            if (count2 > count1)
            {
                if (inArray[j] == '1' && outArray[j] != '1')
                {
                    moveCount++;
                }
            }
            else
            {
                if (inArray[j] == '0' && outArray[j] != '0')
                {
                    moveCount++;
                }
            }
        }

        move[i] = moveCount;  
    }
    for (int i = 0; i < tc; i++)
    {
        printf("%d\n", move[i]); 
    }
    
    return 0;
}