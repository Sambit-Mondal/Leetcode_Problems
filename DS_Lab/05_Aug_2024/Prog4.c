// Q. Write a Program to find the length of the longest Sub-array with the sum of the elements equal to the given value k.

#include <stdio.h>

int longestSubArrayWithSum(int arr[], int n, int k) {
    int maxLength = 0;

    for (int start = 0; start < n; start++) {
        int currentSum = 0;

        for (int end = start; end < n; end++) {
            currentSum += arr[end];

            if (currentSum == k) {
                int currentLength = end - start + 1;
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                }

                
            }
        }
    }

    return maxLength;
}

int main() {
    int n, k;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    int result = longestSubArrayWithSum(arr, n, k);
    printf("The length of the longest sub-array with sum %d is %d\n", k, result);

    return 0;
}