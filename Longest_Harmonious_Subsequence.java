// 594. Longest Harmonious Subsequence (https://leetcode.com/problems/longest-harmonious-subsequence/)

import java.util.*;

class Solution {
    public int findLHS(int[] nums) {

        // Sliding Window + Two pointer approach (TLE)

        // TC = O(n log n)
        // SC = O(1)
        
        // // Sort the array
        // Arrays.sort(nums);

        // // Initialize variables
        // int left = 0;
        // int maxLength = 0;

        // for (int right = 0; right < nums.length; right++) {

        //     // Calculate the difference
        //     int diff = nums[right] - nums[left];

        //     // Till the diff is greater than 1, increase the left pointer
        //     while (diff > 1) {
        //         left++;
        //     }

        //     // If the difference is 1, return the length of the longest harmonious subsequence
        //     if (diff == 1) {
        //         maxLength = Math.max(maxLength, right - left + 1);
        //     }
        // }

        // return maxLength;




        // HashMap approach
        // TC = O(n)
        // SC = O(n)

        Map<Integer, Integer> frequencyMap = new HashMap<>();

        // Initialize the variables
        int maxLength = 0;

        // Store the frequency of each integer in the hashmap
        for (int num : nums) {
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }

        for (int key : frequencyMap.keySet()) {

            // Check if key + 1 exists, for every key
            if (frequencyMap.containsKey(key + 1)) {
                int totalLength = frequencyMap.get(key) + frequencyMap.get(key + 1);

                // Compare the length of the max length with the current length
                maxLength = Math.max(totalLength, maxLength);
            } 
        }

        return maxLength;
    }
}