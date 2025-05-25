// 2131. Longest Palindrome By Concatenating Two Letter Words (https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/)

import java.util.*;

class Longest_Palindrome_By_Concatenating_Two_Letter_Words {
    public int longestPalindrome(String[] words) {
        Map<String, Integer> freq = new HashMap<>();
        for (String word : words) {
            freq.put(word, freq.getOrDefault(word, 0) + 1);
        }

        int ans = 0;
        boolean hasCenter = false;

        for (String word : new HashSet<>(freq.keySet())) {
            String rev = new StringBuilder(word).reverse().toString();
            if (word.equals(rev)) {
                int count = freq.get(word);
                ans += (count / 2) * 4;
                if (count % 2 == 1) {
                    hasCenter = true;
                }
            } else if (freq.containsKey(rev)) {
                int pairs = Math.min(freq.get(word), freq.get(rev));
                ans += pairs * 4;
                freq.put(rev, 0);
            }
        }

        if (hasCenter) {
            ans += 2;
        }
        return ans;
    }
}