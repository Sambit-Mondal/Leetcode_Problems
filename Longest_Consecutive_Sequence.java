// 128. Longest Consecutive Sequence (https://leetcode.com/problems/longest-consecutive-sequence/)

import java.util.*;

class Longest_Consecutive_Sequence {
    public int longestConsecutive(int[] nums) {
        Set<Integer> numMap = new HashSet<>();

        for (int num : nums) {
            numMap.add(num);
        }

        int longestStreak = 0;

        for (int num : nums) {
            if (numMap.contains(num)) {
                int currentStreak = 1;
                int currentNum = num;
                numMap.remove(num);

                int prevNum = currentNum - 1;

                while (numMap.contains(prevNum)) {
                    numMap.remove(prevNum);
                    currentStreak++;
                    prevNum--;
                }

                int nextNum = currentNum + 1;

                while (numMap.contains(nextNum)) {
                    numMap.remove(nextNum);
                    currentStreak++;
                    nextNum++;
                }

                longestStreak = Math.max(currentStreak, longestStreak);
            }
        }

        return longestStreak;
    }
}