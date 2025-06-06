// 347. Top K Frequent Elements (https://leetcode.com/problems/top-k-frequent-elements/)

import java.util.*;

class Top_K_Frequent_Elements {
    public int[] topKFrequent(int[] nums, int k) {
        if (k == nums.length) {
            return nums;
        }

        Map<Integer, Integer> count = new HashMap<>();
        for (int n : nums) {
            count.put (n, count.getOrDefault(n, 0) + 1);
        }

        Queue<Integer> heap = new PriorityQueue<>(
            (n1, n2) -> count.get(n1) - count.get(n2)
        );

        for (int n : count.keySet()) {
            heap.add(n);
            if (heap.size() > k) {
                heap.poll();
            }
        }

        int[] top = new int[k];

        for (int i = k - 1; i >= 0; --i) {
            top[i] = heap.poll();
        }

        return top;
    }
}