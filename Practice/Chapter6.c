// #include <stdio.h>
// int main(){
//     int i = 23;
//     int *j = &i; // Here j is a pointer storing a int value of address of i;
//     printf("This prints the address of i %d\n", j);
//     printf("This prints the value of i %d\n", *j); // *j is the 'value at address' operator
//     printf("This prints the address of the pointer itself or the address of j %d", &j);
//     printf("This will print the value of j or the address of i %d", *(&j)); // it can be interpreted as - &j = the address of j, and the *(&j) = value at address operator
//     return 0;
// }

// // pointer to a pointer
// #include <stdio.h>
// int main()
// {
//     int i, *j, **k;
//     i = 32;
//     j = &i;
//     k = &j;
//     printf("i = %d, address of i = %d, j = %d, address of j = %d, k = %d", i, &i, j, &j, k);
//     return 0;
// }

// Difference between call by reference and call by value
#include <stdio.h>
void wrong_swap(int a, int b);
void swap(int *a, int *b);
int main()
{
    int a = 3, b = 4;
    printf("Before wrong swap a = %d, b = %d\n", a, b);
    wrong_swap(a, b);
    printf("After wrong swap & = %d, b = %d\n", a, b); // doesnt change the global variable
    a = 3;
    b = 4;
    printf("Before swap a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swap & = %d, b = %d", a, b); // changes the global variable
    return 0;
}
void wrong_swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void swap(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}
