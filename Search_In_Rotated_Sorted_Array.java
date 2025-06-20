// 33. Search in Rotated Sorted Array (https://leetcode.com/problems/search-in-rotated-sorted-array/)

// TC = O(log n) [Average, if no duplicates] || O(n) [Worst, in case of duplicates]
// SC = O(1)

class Solution {
    public int search(int[] nums, int target) {
        int start = 0;
        int end = nums.length - 1;
        int mid = -1;

        // Using Binary Search
        while (start <= end) {
            mid = start + (end - start) / 2;

            // If the mid value is equal to target
            if (nums[mid] == target) {
                return mid;
            }

            // If the start value is equal to target
            if (nums[start] == target) {
                return start;
            }

            // If the mid value is equal to target
            if (nums[end] == target) {
                return end;
            }

            // If the left side is sorted or the right side is unsorted
            if (nums[start] < nums[mid] || nums[end] < nums[mid]) {
                if (nums[start] < target && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            
            // If the right side is sorted or the left side is unsorted
            } else if (nums[end] > nums[mid] || nums[start] > nums[mid]) {
                if (nums[end] > target && nums[mid] < target) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            
            // In case of duplicates
            } else {
                start++;
                end--;
            }
        }

        return -1;
    }
}