// 81. Search in Rotated Sorted Array II (https:// leetcode.com/problems/search-in-rotated-sorted-array-ii/)

class Solution {
    public boolean search(int[] nums, int target) {
        // Brute force
        // TC = O(n)
        // SC = O(1)

        // for (int i = 0; i < nums.length; i++) {
        //     if (nums[i] == target) {
        //         return true;
        //     }
        // }

        // return false;



        // Using Binary Search
        // TC = O(n) [Worst]   ||   O(log n) [Average, with low/no duplicates]
        // SC = O(1)

        int start = 0;
        int end = nums.length - 1;
        int mid = -1;

        while (start <= end) {
            mid = start + (end - start) / 2;
            
            // If the mid value is equal to the target
            if (nums[mid] == target) {
                return true;
            }

            // If the start value is equal to the target
            if (nums[start] == target) {
                return true;
            }

            // If the end value is equal to the target
            if (nums[end] == target) {
                return true;
            }

            // Right half is sorted or left half is unsorted
            if (nums[mid] < nums[end] || nums[mid] < nums[start]) {
                if (target > nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            
            // Left half is sorted or right half is unsorted
            } else if (nums[mid] > nums[start] || nums[mid] > nums[end]) {
                if (nums[mid] > target && target >= nums[start]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }

            // Handle duplicates
            } else {
                end--;
            }
        }

        return false;
    }
}