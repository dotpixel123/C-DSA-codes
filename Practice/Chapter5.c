// #include <stdio.h>
// int display();
// int display(){
//     printf("This is a display function."); 
// }
// int main()
// {
//     printf("Running the display function\n"); 
//     display();
//     return 0;
// }

// #include <stdio.h>
// void goodmorning();
// void goodafternoon(); 
// void goodnight();
// int main(){
//     goodmorning(); 
//     return 0;
// }
// void goodmorning(){
//     printf("Good morning!\n"); 
//     goodafternoon(); 
//     goodnight(); 
// }
// void goodafternoon(){
//     printf("Good afternoon!\n"); 
// }
// void goodnight(){
//     printf("Good night!\n"); 
// }

// // sum function
// #include <stdio.h>
// int sum(int a, int b); 
// int main(){
//     sum(36,2); 
//     return 0;
// }
// int sum(int n1, int n2){
//     printf("Sum of 1st and 2nd number = %d", n1 + n2);
//     return 0; 
// }

// // doubt question
// #include <stdio.h>
// int change(int num);
// int main(){
//     int b = 100; 
//     printf("The value of b before change is %d \n", b); 
//     change(b); 
//     printf("The value of b now is also %d \n", b); 
//     return 0;
// }
// int change(int a){
//     a = 29; 
// }

// but if we print the value of the variable in the function itself it prints the value of the copy but like the previous case it doesnt change the global variable
#include <stdio.h>
void change(int num);
int main(){
    int b = 100; 
    change(b); 
    return 0;
}
void change(int a){
    printf("The value of b before change is %d \n", a); 
    a = 29; 
    printf("The value of a now has changed to %d \n", a); 

}

// // Recursion (factorial of a number)
// #include <stdio.h>
// int fact(int x); 
// int main(){
//     int num, factorial; 
//     printf("Enter the number\n"); 
//     scanf("%d", &num); 
//     factorial = fact(num); 
//     printf("The factorial of the number is %d", factorial); 
//     return 0;
// }
// int fact(int x){
//     if (x == 1 || x == 0){
//         return 1; 
//     }
//     else
//         return x * fact(x-1);  
// }