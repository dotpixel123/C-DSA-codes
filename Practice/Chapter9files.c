// #include <stdio.h>
// int main(){
//     FILE *fpointer = fopen("newblankfile.txt", "w");
//     fprintf(fpointer, "Shourya\nShubham\nShreshth"); 
//     fclose(fpointer); 
//     return 0;
// }

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// int find_nth_term(int n, int a, int b, int c) {
    /*
    if n == 1, 2, 3
        return a
        
    else if n == 2
        return b
    else if n == 3
        return c
    
    else if n > 3
        return nthterm(n-1, a, b, c) + nthterm(n-2, a, b, c) + nthterm(n-3, a, b, c)
        
    else n ;
        
    */
//     if (n == 1) {
//         return a;
//     }
//     else if (n == 2) {
//         return b;
//     }
//     else if (n == 3) {
//         return c;
//     }
//     else if (n > 3) {
//         return find_nth_term(n-1, a, b, c) + find_nth_term(n-2, a, b, c) + find_nth_term(n-2, a, b, c);
//     }
// }

void frequency(char string[], char num[]){
    int arr[10];
    for (int i = 0; i < 10; i++) {
        int count = 0;
        for (int j = 0; j < strlen(string); j++)
        {   
            if (num[i] == string[j])
            {
                count++; 
            }
        arr[i] = count;
        }
    }
    for (int i = 0; i< 10; i++) {
        printf("%d ", arr[i]);
    }
}

int main(){
    char string[1000];
    scanf("%s", string); 
    char num[10] = "0123456789";
    frequency(string, num);
}

