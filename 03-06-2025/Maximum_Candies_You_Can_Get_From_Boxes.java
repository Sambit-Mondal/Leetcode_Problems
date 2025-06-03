// 1298. Maximum Candies You Can Get From Boxes (https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/)

import java.util.*;

class Maximum_Candies_You_Can_Get_From_Boxes {
    public int maxCandies(
        int[] status,
        int[] candies,
        int[][] keys,
        int[][] containedBoxes,
        int[] initialBoxes
    ) {
        int n = status.length;
        boolean[] canOpen = new boolean[n];
        boolean[] hasBox = new boolean[n];
        boolean[] used = new boolean[n];

        for (int i = 0; i < n; ++i) {
            canOpen[i] = (status[i] == 1);
        }

        Queue<Integer> q = new LinkedList<>();
        int ans = 0;
        for (int box : initialBoxes) {
            hasBox[box] = true;
            if (canOpen[box]) {
                q.offer(box);
                used[box] = true;
                ans += candies[box];
            }
        }

        while (!q.isEmpty()) {
            int bigBox = q.poll();
            for (int key : keys[bigBox]) {
                canOpen[key] = true;
                if (!used[key] && hasBox[key]) {
                    q.offer(key);
                    used[key] = true;
                    ans += candies[key];
                }
            }
            for (int box : containedBoxes[bigBox]) {
                hasBox[box] = true;
                if (!used[box] && canOpen[box]) {
                    q.offer(box);
                    used[box] = true;
                    ans += candies[box];
                }
            }
        }

        return ans;
    }
}