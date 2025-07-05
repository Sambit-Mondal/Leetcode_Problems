// Minimum Time to Reach Destination in Directed Graph (https://leetcode.com/problems/minimum-time-to-reach-destination-in-directed-graph/
// Biweekly Contest 160

// TC = O((N + E) * log N)
// SC = O(N + E)

import java.util.*;

class Solution {
    public int minTime(int n, int[][] edges) {;

        // Initialise the adjacency list
        @SuppressWarnings("unchecked")
        List<int[]>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();
        for (int[] e : edges) {
            int u = e[0], v = e[1], s = e[2], eTime = e[3];
            graph[u].add(new int[]{v, s, eTime});
        }

        // Dijkstra-like BFS: state = (node, time)
        int[] minTime = new int[n];
        Arrays.fill(minTime, Integer.MAX_VALUE);
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));
        pq.offer(new int[]{0, 0});
        minTime[0] = 0;

        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int node = cur[0], t = cur[1];
            if (node == n - 1) return t;

            // If already found a better time to this node, skip
            if (t > minTime[node]) continue;

            // Try all outgoing edges
            for (int[] edge : graph[node]) {
                int next = edge[0], start = edge[1], end = edge[2];
                // Wait until the earliest possible time to use the edge
                int nextTime = Math.max(start, t);
                if (nextTime <= end) {
                    // Arrive at next node at nextTime + 1
                    if (minTime[next] > nextTime + 1) {
                        minTime[next] = nextTime + 1;
                        pq.offer(new int[]{next, nextTime + 1});
                    }
                }
            }

            // Wait at current node (only if not already stuck in a loop)
            if (t + 1 < minTime[node]) {
                minTime[node] = t + 1;
                pq.offer(new int[]{node, t + 1});
            }
        }

        return -1;
    }
}