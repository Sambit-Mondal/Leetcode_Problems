// 509. Fibonacci Number (https://leetcode.com/problems/fibonacci-number/)

// TC = O(n)
// SC = O(1)

class Solution {
    public int fib(int n) {

        // Base condition
        if (n <= 1) {
            return n;
        }

        // Recursive approach
        // return fib(n - 1) + fib(n - 2);

        // Initialise variables
        int a = 0;
        int b = 1;

        // Iterative approach
        for (int i = 2; i <= n; i++) {
            int temp = b;
            b = a + b;
            a = temp;
        }

        return b;
    }
}