// Biweekly Contest 159 - Problem 1: Minimum Adjacent Steps To Alternate Parity (https://leetcode.com/problems/minimum-adjacent-steps-to-alternate-parity/) 

// TC = O(n)
// SC = O(n)

import java.util.*;

class Solution {
    public int minSwaps(int[] nums) {
        
        // To store the even and the odd indices in the array nums
        List<Integer> evenIndices = new ArrayList<>();
        List<Integer> oddIndices = new ArrayList<>();

        // Adding the even and odd indices respectively to the lists
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] % 2 == 0) {
                evenIndices.add(i);
            } else {
                oddIndices.add(i);
            }
        }

        // Counting the elements in the lists
        int evenCount = evenIndices.size();
        int oddCount = oddIndices.size();

        // If the evenCount - oddCount is greater than 1, it is impossible to rearrange
        if (Math.abs(evenCount - oddCount) > 1) {
            return -1;
        }

        // Starting with even or odd
        if (evenCount == oddCount) {
            return Math.min(getSwapsCount(evenIndices, 0), getSwapsCount(oddIndices, 0));
        } else if (evenCount > oddCount) {
            return getSwapsCount(evenIndices, 0);
        } else {
            return getSwapsCount(oddIndices, 0);
        }
    }

    // Helper function to determine the number of swaps
    public int getSwapsCount (List<Integer> indices, int start) {
        int swaps = 0;

        for (int i = 0; i < indices.size(); i++) {
            swaps += Math.abs(indices.get(i) - (start + 2 * i));
        }

        return swaps;
    }
}