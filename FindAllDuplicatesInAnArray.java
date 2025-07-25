// 442. Find All Duplicates in an Array (https://leetcode.com/problems/find-all-duplicates-in-an-array/)

// TC = O(n)
// SC = O(n)

import java.util.*;

class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        Map<Integer, Integer> numMap = new HashMap<>();
        List<Integer> duplicates = new ArrayList<>();

        for (int num : nums) {
            numMap.put(num, numMap.getOrDefault(num, 0) + 1);
        }

        for (int num : numMap.keySet()) {
            if (numMap.get(num) == 2) {
                duplicates.add(num);
            }
        }

        return duplicates;
    }
}