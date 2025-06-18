// 5. Longest Palindromic Substring (https://leetcode.com/problems/longest-palindromic-substring/)

// TC = O(n2)
// SC = O(1)

class Solution {
    public String longestPalindrome(String s) {
        // If the String is empty
        if (s == null || s.length() == 0) {
            return "";
        }

        // Declaring two variables to denote start and end of the substring
        int start = 0;
        int end = 0;

        // Traverse through the string
        for (int i = 0; i < s.length(); i++) {
            int odd = expand(s, i, i);
            int even = expand(s, i, i + 1);
            int maxLength = Math.max(odd, even);

            // If max length > current length
            if (maxLength > end - start) {
                start = i - (maxLength - 1) / 2;
                end = i + maxLength / 2;
            }
        }
        
        return s.substring(start, end + 1);
    }

    private int expand(String s, int left, int right) {
        // Using two pointers
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }

        return right - left - 1;
    }
}