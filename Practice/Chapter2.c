// // CORRECT
// #include <stdio.h>
// int main(){
//     float a = 103;
//     printf("%f",a/3);
//     return 0;
// } 
// // WRONG
// #include <stdio.h>
// int main(){
//     int a = 103;
//     printf("%f",a/3);
//     return 0;
// }
// #include <stdio.h>
// int main(){
//     printf("%f",103/3);
//     return 0;
// }

// // Arithmetic Operators 
// #include <stdio.h>
// #include <math.h>
// int main(){
//     float a = 5;
//     float b = 6;
//     float c = a*b;
//     float d = a/b;
//     // Modulus operator returns remainder
//     int x = 8;
//     int y = 3;
//     int r = x%y;
//     // No operator present to perform exponentiation 
//     printf("The value of 3^3 is %f \n", pow(3,3));
//     // a * b = c; not valid as = is used to assign value and a * b is already 32 which doesnt make sense 
//     printf("The value of a %f \n", a);
//     printf("The value of a+b %f \n", a+b);
//     printf("The value of a*b %f \n", c);
//     printf("The value of a/b %f \n", a/b);

//     printf("The remainder when x is divided by y is %d \n", r);

//     return 0;
// }

// // Operator precedence in C
// #include <stdio.h>

// int main(){
//     int a = 3;
//     int b = 2;
//     printf("The value of 4*a/3*b is %d ", 4*a/3*b);
//     // it is solved as (4*a/3)*b i.e. from left to right
//     return 0;
// }


