// // Question 1
// #include <stdio.h>
// int main(){
//     int i = 28;
//     int *j = &i;
//     printf("%d %u %p", j, j, j);
//     return 0;
// }

// Question 2
#include <stdio.h>
void add_of_var(int i)
{
    printf("%u", &i);
}
int main()
{
    int a = 23;
    printf("%u\n", &a);
    add_of_var(a);
    return 0;
}