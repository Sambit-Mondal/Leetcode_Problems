// 56. Merge Intervals (https://leetcode.com/problems/merge-intervals/)

// TC = O(n log n)
// SC = O(n)

import java.util.*;

class Solution {
    public int[][] merge(int[][] intervals) {

        // Sorting the array
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        // Initialise an ArrayList
        List<int[]> mergedIntervals = new ArrayList<>();

        // To track the previous interval
        int[] prev = intervals[0];

        // Iterate the array
        for (int i = 1; i < intervals.length; i++) {

            // Initialise an array to track the current element 
            int[] current = intervals[i];

            // If the first int of current element is less than or equal to the second int of prev element
            if (current[0] <= prev[1]) {
                prev[1] = Math.max(prev[1], current[1]);

            // If the first int of current element is less than or equal to the second int of prev element
            } else {
                mergedIntervals.add(prev);
                prev = current;
            }
        }

        mergedIntervals.add(prev);

        // Converting the Arraylist to array of the Arraylist's size
        return mergedIntervals.toArray(new int[mergedIntervals.size()][]);
    }
}