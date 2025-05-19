// 3024. Type of Triangle (https://leetcode.com/problems/type-of-triangle/)

import java.util.*;

class Type_of_Triangle {
    public String triangleType(int[] nums) {
        Arrays.sort(nums);

        if (nums[0] + nums[1] > nums[2] && nums[1] + nums[2] > nums[0] && nums[0] + nums[2] > nums[2]) {
            if (nums[0] == nums[1] && nums[1] == nums[2] && nums[0] == nums[2]) {
                return "equilateral";
            } else if (nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) {
                return "isosceles";
            } else {
                return "scalene";
            }
        } else {
            return "none";
        }
    }
}