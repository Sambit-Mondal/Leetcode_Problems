// 53. Maximum Subarray (https://leetcode.com/problems/maximum-subarray/)

// TC = O(n)
// SC = O(n)

class Solution {
    public int maxSubArray(int[] nums) {

        // Initialise the variables
        int globalMax = Integer.MIN_VALUE;
        int currentMax = 0;

        // Iterate through the array
        for (int i = 0; i < nums.length; i++) {

            // Increment currentMax by adding each `i` to it
            currentMax += nums[i];

            // Update globalMax with currentMax if currentMax is larger than the globalMax
            globalMax = Math.max(currentMax, globalMax);

            // Set currentMax to 0 if it becomes negative (since negative elements are present)
            currentMax = Math.max(currentMax, 0);
        }

        // Return globalMax
        return globalMax;
    }
}