// 15. 3Sum (https://leetcode.com/problems/3sum/)

// TC = O(n2)
// SC = O(1)

import java.util.*;

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();

        // Sorting the array 'nums'
        Arrays.sort(nums);

        // Traversing the array
        for (int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Initialising variables
            int j = i + 1;
            int k = nums.length - 1;

            // Using two pointers
            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];

                if (total < 0) {
                    j++;
                } else if (total > 0) {
                    k--;
                } else {
                    result.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    j++;

                    // Increment j to avoid same triplet
                    while (nums[j] == nums[j - 1] && j < k) {
                        j++;
                    }
                }
            }
        }

        return result;
    }
}