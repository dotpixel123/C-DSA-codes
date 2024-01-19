
// Rotate array by k elements: Write a function in C to rotate an array of integers by k elements to the right. For example, if the input array is [1, 2, 3, 4, 5] and k is 2, the output should be [4, 5, 1, 2, 3].
#include <stdio.h>

void rotatebyK(int arr[], int n, int k){
    for (int i = 0; i < k; i++)
    {
        for (int j = n-1; j > 0; j--)
        {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

}

#include <stdio.h>
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int k = 2;
    rotatebyK(arr, n, k);
}
