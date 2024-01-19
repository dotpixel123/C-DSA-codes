
// q. Write a program in C to count the total number of duplicate elements in an array.
#include <stdio.h>
int dupCount(int arr[], int n){
    int count = 0; 
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n-1; j++)
        {
            if (arr[i] == arr[j])
            {
                count++; 
            }
            
        }
        
    }
    return count; 
    
}

int main(){
    int arr[7] = {1, 2, 3, 4, 5, 5, 5};
    int count = dupCount(arr, 7); 
    printf("%d", count);
    return 0;
}