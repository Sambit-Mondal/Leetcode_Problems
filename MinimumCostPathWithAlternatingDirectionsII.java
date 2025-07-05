// Minimum Cost Path With Alternating Directions II (https://leetcode.com/problems/minimum-cost-path-with-alternating-directions-ii/)
// Biweekly Contest 160

// TC = O(mn log(mn))
// SC = O(mn)

import java.util.*;

class Solution {
    static class State {
        int i, j, parity;
        long cost;

        State(int i, int j, int parity, long cost) {
            this.i = i;
            this.j = j;
            this.parity = parity;
            this.cost = cost;
        }
    }

    public long minCost(int m, int n, int[][] waitCost) {

        // Initialise dp[i][j][p] to store the minimum cost to reach (i, j) with parity
        // p
        long[][][] dp = new long[m][n][2];

        // Initialise the cost to the max
        for (long[][] arr2 : dp) {
            for (long[] arr : arr2) {
                Arrays.fill(arr, Long.MAX_VALUE);
            }
        }

        // Start at (0,0) at second 1
        dp[0][0][0] = (0 + 1) * (0 + 1);

        // Using Min-heap priority queue
        PriorityQueue<State> pq = new PriorityQueue<>(Comparator.comparingLong(a -> a.cost));
        pq.offer(new State(0, 0, 0, dp[0][0][0]));

        int[] dx = { 1, 0 };
        int[] dy = { 0, 1 };

        while (!pq.isEmpty()) {
            State cur = pq.poll();
            int i = cur.i, j = cur.j, parity = cur.parity;
            long cost = cur.cost;

            // If the current cost is higher than the stored cost, skip it
            if (dp[i][j][parity] < cost) {
                continue;
            }

            // If parity is 0 (odd)
            if (parity == 0) {

                // Try moving right or down
                for (int d = 0; d < 2; d++) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (ni < m && nj < n) {
                        long ncost = cost + (long) (ni + 1) * (nj + 1);
                        if (dp[ni][nj][1] > ncost) {
                            dp[ni][nj][1] = ncost;
                            pq.offer(new State(ni, nj, 1, ncost));
                        }
                    }
                }

                // If parity is 1 (even)
            } else {

                // Wait in place
                long ncost = cost + waitCost[i][j];
                if (dp[i][j][0] > ncost) {
                    dp[i][j][0] = ncost;
                    pq.offer(new State(i, j, 0, ncost));
                }
            }
        }

        return Math.min(dp[m - 1][n - 1][0], dp[m - 1][n - 1][1]);
    }
}