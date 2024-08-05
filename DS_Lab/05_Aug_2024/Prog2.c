// Q. Write a program to find the number of pair of elements in the given array, whose sum is equal to k, given array arr and an integer k.

#include <stdio.h>

int countPairsWithSum(int arr[], int n, int k) {
    int count = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == k) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    int num;

    printf("Enter the size of the array: ");
    scanf("%d", &num);

    int arr[num];

    printf("Enter the elements of the array: \n");
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 6;
    
    int result = countPairsWithSum(arr, n, k);
    printf("Number of pairs with sum %d: %d\n", k, result);
    
    return 0;
}