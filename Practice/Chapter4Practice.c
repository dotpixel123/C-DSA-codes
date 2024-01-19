// // To find the multiplication table of a number given by the user
// #include <stdio.h>
// int main(){
//     int n; 
//     printf("Enter your number\n");
//     scanf("%d",&n);
//     for (int i = 0; i <= 10; i++){
//         printf("%d times %d is %d\n",n, i, i*n);
//     }
//     return 0;
// }

// // Question 2
// #include <stdio.h>
// int main(){
//     for (int i = 10; i; i--){
//         printf("10 times %d is %d\n", i, 10*i);
//     }
//     return 0;
// }

// // Sum till n numbers
// #include <stdio.h>
// int main(){
//     int n, i = 0, sum = 0;
//     printf("Enter the value of n\n");
//     scanf("%d",&n);
//     while (i <= n){
//         sum += i;
//         i++;
//     }
//     printf("the value of sum is %d", sum);
//     return 0;
// }

// // Question 5
// #include <stdio.h>
// int main(){
//     int n, sum = 0; 
//     printf("Enter the value of n\n");
//     scanf("%d", &n);
//     for (int i = 0; i <= n; i++){
//         sum += i;
//     }
//     printf("%d", sum);
//     return 0;
// }
// #include <stdio.h>
// int main(){
//     int n, i = 0, sum = 0; 
//     printf("Enter the value of n\n");
//     scanf("%d", &n);
//     do {
//         sum +=i;
//         i++;
//     } 
//     while(i<=n);
//     printf("%d", sum);
//     return 0;
// }

// // Question 7
// #include <stdio.h>
// int main(){
//     int n = 10, sum = 0; 
//     printf("Enter the value of n\n");
//     scanf("%d", &n);
//     for (int i = 1; i<=n; i++){
//         sum += (8*i);
//     }
//     printf("%d", sum);
//     return 0;
// }
// #include <stdio.h>
// int main(){
//     int i = 1, n, sum = 0; 
//     printf("Enter the value of n\n");
//     scanf("%d", &n);
//     while (i<=n){
//         sum += 8*i;
//         i++;
//     }
//     printf("%d", sum);
//     return 0;
// }

// // Question 8 - factorial
// #include <stdio.h>
// int main(){
//     int num, fact = 1; 
//     printf("Enter the num\n");
//     scanf("%d", &num);
//     for (int i = num; i >= 1 ; i--){
//         fact *= i;
//     }
//     printf("%d", fact);
//     return 0;
// }
// #include <stdio.h>
// int main(){
//     int n, fact = 1; 
//     printf("Enter the value of n\n"); 
//     scanf("%d", &n);
//     int i = n; 
//     while (i>=1){
//         fact *= i;
//         i--;
//     }
//     printf("%d", fact);
//     return 0;
// }

// Question 10 to check for prime number
#include <stdio.h>
int main(){
    int num = 16, prime = 1; 
    for (int i = 2; i < num; i++){
        if (num % i == 0){
            prime = 0;
            break;
        }
        // else 
        //     continue;
    }
    if (prime == 1)
        printf("It is a prime number");
    else 
        printf("Number is not prime");
    return 0;
}