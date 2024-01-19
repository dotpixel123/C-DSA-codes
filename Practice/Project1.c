// Number guessing game
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>   
int main(){  
    int num, guess;  
    srand(time(0));
    num = rand()%100 + 1;
    printf("Guess number between 1 to 100\n");
    while (guess != num){
        printf("Enter your guess\n");
        scanf("%d", &guess);
        if (guess == num){
            printf("You have guessed correctly!");
            break;
        }
        else if (guess < num)
            printf("Guess higher\n");
        else if (guess > num)
            printf("Guess lower\n");
        else
            continue;
    }
    return 0; 
}
