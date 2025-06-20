// 424. Longest Repeating Character Replacement (https://leetcode.com/problems/longest-repeating-character-replacement/)

// TC = O(n)
// SC = O(1)

class Solution {
    public int characterReplacement(String s, int k) {
        int[] count = new int[26];
        int maxFrequency = 0;
        int result = 0;
        int start = 0;

        // Using Sliding Window
        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i) - 'A']++;
            maxFrequency = Math.max(maxFrequency, count[s.charAt(i) - 'A']);

            while ((i - start + 1) - maxFrequency > k) {
                count[s.charAt(start) - 'A']--;
                start++;
            }

            result = Math.max(result, i - start + 1);
        }

        return result;
    }
}