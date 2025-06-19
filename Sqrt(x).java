// 69. Sqrt(x) (https://leetcode.com/problems/sqrtx/)

// TC = O(log n)
// SC = O(1)

class Solution {
    public int mySqrt(int x) {
        // As, the sq. root of 0 or 1 is 0 or 1, respectively
        if (x == 0 || x == 1) {
            return x;
        }

        // Declaring the variables
        int start = 0;
        int end = x;
        int mid = -1;

        while (start <= end) {
            // To avoid integer overflow
            mid = start + (end - start) / 2;

            // If the mid^2 comes out to be less than x
            if ((long) mid * mid < (long) x) {
                start = mid + 1;
                
                // If the mid^2 comes out to be greater than x
            } else if ((long) mid * mid > (long) x) {
                end = mid - 1;

                // If the mid^2 comes out to be equal to x
            } else {
                return mid;
            }
        }

        return Math.round(end);
    }
}