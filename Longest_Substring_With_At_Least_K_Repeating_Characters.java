// 395. Longest Substring with At Least K Repeating Characters (https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/)

// TC = O(n2)
// SC = O(n)

import java.util.*;

class Solution {
    public int longestSubstring(String s, int k) {

        // Initialize HashMap to store the frequencies of each character in the string
        Map<Character, Integer> charFrequency = new HashMap<>();

        // Store the character-frequency in a key-value pair
        for (char str : s.toCharArray()) {
            charFrequency.put(str, charFrequency.getOrDefault(str, 0) + 1);
        }

        for (char ch : charFrequency.keySet()) {
            if (charFrequency.get(ch) < k) {

                // Split the characters whose frequency < k
                String[] parts = s.split(String.valueOf(ch));

                int max = 0;

                // Recursively getting the longestSubstring
                for (String part : parts) {
                    max = Math.max(max, longestSubstring(part, k));
                }

                return max;
            }
        }

        // All characters occur at least k times
        return s.length();
    }
}