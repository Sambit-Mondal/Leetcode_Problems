// 209. Minimum Size Subarray Sum (https://leetcode.com/problems/minimum-size-subarray-sum/)

// TC = O(n)
// SC = O(1)

class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int currentSum = 0;
        int start = 0;
        int minLength = Integer.MAX_VALUE;

        // Traverse through the array
        for (int i = 0; i < nums.length; i++) {

            // Incrementing currentSum by nums[i]
            currentSum += nums[i];

            while (currentSum >= target) {
                // Calculating the length of the subarray by right end - left end + 1
                if (i - start + 1 < minLength) {
                    minLength = i - start + 1;
                }

                // Decrementing currentSum by nums[i]
                currentSum -= nums[start];
                start++;
            }
        }

        // If no subarray is found, return 0, otherwise, return the minLength of the subarray
        return minLength != Integer.MAX_VALUE ? minLength : 0;
    }
}