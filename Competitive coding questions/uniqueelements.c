
// Q. Write a program in C to print all unique elements in an array.
#include <stdio.h>
int main(){
    int arr[7] = {1, 2, 3, 4, 4, 3, 5};
    int unique = 1;
    for (int i = 0; i < 7; i++)
    {
        for (int j = i+1; j < 7; j++)
        {
            if (arr[i] == arr[j])
            {
                unique = 0;
                continue;
            }

        }
        if (unique == 1)
        {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}