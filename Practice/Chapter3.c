// // if else statements
// #include <stdio.h>
// int main(){
//     int a;
//     printf("Enter a number\n");
//     scanf("%d",&a);
//     if(a%2 == 0){
//         printf("Your number is even");
//     }
//     else{
//         printf("Your number is odd");
//     }
//     return 0;
// }

// // Check if a person can drive
// #include <stdio.h>
// int main()
// {
//     int age;
//     int disable;
//     printf("Enter your age\n");
//     scanf("%d", &age);
//     printf("If disable, enter 1. Else enter 0\n");
//     scanf("%d",&disable);
//     if (age <= 70 && age > 18 && !disable == 1) // '&&' repesents 'and' whereas a single '&' represents bitwise operator. '||' represents 'or'. '!' represents 'not'.
//     {
//         printf("You can drive!");
//     }
//     else
//     {
//         printf("You can't drive");
//     }

//     return 0;
// }

// if elif else to convert marks to grade
#include <stdio.h>
int main(){
    int marks;
    printf("Enter your marks here:\n");
    scanf("%d",&marks);
    if(90<=marks && marks<=100){
        printf("Your grade is A");
    }
    else if(80<=marks && marks<90)
        printf("Your grade is B");
    else if(70<=marks && marks<80)
        printf("Your grade is C");
    else if(60<=marks && marks<70)
        printf("Your grade is D");
    else if(marks < 60)
        printf("Your grade is F");
    else
        printf("Enter correct marks");
    return 0;
}

// // Short way to write if else statements (conditional operators)
// #include <stdio.h>
// int main(){
//     int num;
//     printf("Enter your number here\n");
//     scanf("%d",&num);
//     (num<100)? printf("Your number is less than 100") : printf("Your number is more than 100");
//     return 0;
// }

// Switch case control instruction
#include <stdio.h>
int main(){
    int rating;
    printf("Enter a rating from 1 to 5\n");
    scanf("%d", &rating);
    switch (rating)
    {
    case 1:
        printf("Your rating is 1");
        break;
    case 2:
        printf("Your rating is 2");
        break;
    case 3:
        printf("Your rating is 3");
        break;
    case 4:
        printf("Your rating is 4");
        break;
    case 5:
        printf("Your rating is 5");
        break;    
    default:
        printf("Invalid rating");
        break;
    }
    return 0;
}