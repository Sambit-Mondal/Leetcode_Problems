// 153. Find Minimum in Rotated Sorted Array (https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)

class Solution {
    public int findMin(int[] nums) {
        // Brute Force
        // TC = O(n)
        // SC = 1
        // int minimumElement = nums[0];
    
        // for (int i = 0; i < nums.length; i++) {
        //     int currentElement = nums[i];

        //     if (minimumElement > currentElement) {
        //         minimumElement = currentElement;
        //     }
        // }

        // return minimumElement;



        // Using Binary Search
        // TC = O(log n)
        // SC = O(1)

        int start = 0;
        int end = nums.length - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            // If mid <= end, then the min element should be to the left of the mid (Sorted)
            if (nums[mid] <= nums[end]) {
                end = mid;
                // If mid > end, then the min element should be to the right of the mid (Sorted)
            } else {
                start = mid + 1;
            }
        }

        return nums[start];
    }
}