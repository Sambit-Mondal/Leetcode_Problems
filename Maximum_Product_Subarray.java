// 152. Maximum Product Subarray (https://leetcode.com/problems/maximum-product-subarray/)

// TC = O(n)
// SC = O(1)

class Solution {
    public int maxProduct(int[] nums) {
        int res = Integer.MIN_VALUE;

        // Handles cases where only 1 number or no number is present in the array
        for (int n : nums) {
            res = Math.max(res, n);
        }

        // Declare 2 variables to track the current min and max
        int currentMin = 1;
        int currentMax = 1;

        // Iterate through the array
        for (int n : nums) {
            int temp = n * currentMax;

            // Tracking the current min and max
            currentMax = Math.max(temp, Math.max(currentMin * n, n));
            currentMin = Math.min(temp, Math.min(currentMin * n, n));

            // Finding the max product
            res = Math.max(res, currentMax);
        }

        return res;
    }
}