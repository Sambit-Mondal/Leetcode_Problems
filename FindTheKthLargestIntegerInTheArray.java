// 1985. Find the Kth Largest Integer in the Array (https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/)

// TC = O(n.L log n)
// SC = O(n)

import java.util.*;

class Solution {
    public String kthLargestNumber(String[] nums, int k) {

        // Sort the array numerically using a custom comparator
        Arrays.sort(nums, new Comparator<String>() {

            public int compare (String a, String b) {

                // Compare by length first, then lexicographically
                if (a.length() != b.length()) {
                    return a.length() - b.length();
                }

                return a.compareTo(b);
            }
        });

        // Return the kth largest number
        return nums[nums.length - k];
    }
}