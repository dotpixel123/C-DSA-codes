// // Question 1
// #include <stdio.h>
// int avg(int a, int b, int c);
// int main()
// {
//     int average = avg(25, 24, 23);
//     printf("%d", average);
//     return 0;
// }
// int avg(int d, int e, int f)
// {
//     return (d + e + f) / 3;
// }

// // Question 4
// #include <stdio.h>
// int fib(int n);
// int main()
// {
//     int fibnum,n;
//     fibnum = fib(n=40);
//     printf("%d", fibnum);
//     return 0;
// }
// int fib(int n)
// {
//     if (n == 0)
//     {
//         return 0 ;
//     }
//     else if (n == 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return fib(n - 1) + fib(n - 2);
//     }
// }

// // Question 5
// #include <stdio.h>
// int sumTill(int n);
// int main()
// {
//     int sum, n;
//     sum = sumTill(n = 3);
//     printf("%d", sum);
//     return 0;
// }
// int sumTill(int n)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     else
//     {
//         return n + sumTill(n - 1);
//     }
// }

// Question 6;
#include <stdio.h>
void print_pattern(int n)
{
    // printf("* ");
    if (n == 1)
    {
        printf("* ");
    }
    else
    {
        print_pattern(n - 1);
    }
}
int main()
{
    print_pattern(3);
    return 0;
}
