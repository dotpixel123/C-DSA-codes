// // Program to find if pass or fail
// #include <stdio.h>
// int main()
// {
//     int phy;
//     int maths;
//     int chem;
//     int total_mark = 100;
//     int pass_mark = 0.33 * total_mark;

//     printf("Enter your physics marks here\n");
//     scanf("%d", &phy);
//     printf("Enter your maths marks here\n");
//     scanf("%d", &maths);
//     printf("Enter your chemistry marks here\n");
//     scanf("%d", &chem);

//     int avg = (phy + maths + chem) / 3;

//     if (phy > pass_mark && maths > pass_mark && chem > pass_mark && avg > 40)
//     {
//         printf("You have passed");
//     }
//     else
//     {
//         printf("You have failed");
//     }
//     return 0;
// }

// // Calculation of income tax paid
// #include <stdio.h>
// int main()
// {
//     int salary;
//     printf("Enter your salary here\n");
//     scanf("%d", &salary);
//     if (salary > 250000 && salary <= 500000)
//     {
//         printf("You have to pay tax equal to %f", salary * 0.05);
//     }
//     else if (salary > 500000 && salary <= 1000000)
//     {
//         printf("You have to pay tax equal to %f",salary * 0.2);
//     }
//     else if (salary > 1000000)
//     {
//         printf("You have to pay tax equal to %f",salary * 0.3);
//     }
//     else
//     {
//         printf("You don't have to pay any income tax");
//     }

//     return 0;
// }

// // To check if a year is leap year or not
// #include <stdio.h>
// int main(){
//     int year;
//     printf("Enter the year\n");
//     scanf("%d",&year);
//     if (year%4 == 0 && year%100 == 0 && year%400 == 0){
//         printf("The year is a leap year");
//     }
//     else{
//         printf("The year is not a leap year");
//     }
//     return 0;
// }

// // To check if a character is lowercase or not
// #include <stdio.h>
// int main(){
//     char a;
//     printf("Enter a character\n");
//     scanf("%c",&a);
//     if (a <= 122 && a >= 97){
//         printf("Your character is a lowercase character");
//     }
//     else{
//         printf("Your character is not a lowercase character");
//     }
//     return 0;
// }

// // to find great of four numbers
// #include <stdio.h>
// int main(){
//     int num1, num2, num3, num4;
//     printf("Enter your numbers\n");
//     scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
//     // printf("%d %d %d %d", num1, num2, num3, num4);
//     if (num1 > num2 && num1 > num3 && num1 > num4){
//         printf("%d is the greatest number",num1);
//     }
//     else if (num2 > num1 && num2 > num3 && num2 > num4){
//         printf("%d is the greatest number",num2);
//     }
//     else if (num3 > num2 && num3 > num1 && num3 > num4){
//         printf("%d is the greatest number",num3);
//     }
//     else{
//         printf("%d is the greatest number",num4);
//     }
//     return 0;
// }

// #include <stdio.h>
// int main(){
//     int num1, num2, num3, num4;
//     int great_num = num1;
//     printf("Enter your numbers\n");
//     scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
//     if (num2 > great_num)
//     {
//         great_num = num2;
//         if (num3 > great_num)
//         {
//         great_num = num3;
//         }
//             if (num4 > great_num)
//             {
//             great_num = num4;
//             }
//     }
//     printf("%d is your greatest number", great_num);
//     return 0;
// }