// q. Write a program in C to copy the elements of one array into another array.
#include <stdio.h>
int main(){
    int arr[3];
    int arr_cpy[3];
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        arr_cpy[i] = arr[i];
    }
    for (int i = 0; i < 3; i++)
        printf("%d ", arr_cpy[i]);
    return 0;
}
