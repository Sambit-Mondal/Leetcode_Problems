// 11. Container With Most Water (https://leetcode.com/problems/container-with-most-water/)

// TC = O(n)
// SC = O(1)

class Solution {
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int currentArea = 0;
        int maxArea = 0;

        while (left < right) {
            // Using two pointer method
            currentArea = Math.min(height[left], height[right]) * (right - left);
            maxArea = Math.max(currentArea, maxArea);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
}