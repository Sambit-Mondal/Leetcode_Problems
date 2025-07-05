// Minimum Stability Factor of Array (https://leetcode.com/problems/minimum-stability-factor-of-array/)
// Biweekly Contest 160

// class Solution {

//     // Helper function to calculate GCD (Euclidean)
//     private static int gcd(int a, int b) {
//         while (b != 0) {
//             int t = a % b;
//             a = b;
//             b = t;
//         }
//         return a;
//     }

//     public int minStable(int[] nums, int maxC) {
//         int n = nums.length;
//         int left = 1, right = n;
//         int ans = 0;

//         // Implementing Binary search
//         while (left <= right) {
//             int mid = (left + right) / 2;
//             if (canReduce(nums, mid, maxC)) {
//                 // If we can break all stable subarrays of length mid, try shorter
//                 right = mid - 1;
//             } else {
//                 // Otherwise, try longer and record this as possible answer
//                 ans = mid;
//                 left = mid + 1;
//             }
//         }
//         return ans;
//     }

//     private static boolean canReduce(int[] nums, int len, int maxC) {
//         int n = nums.length;
//         int changesNeeded = 0;
//         int[] window = new int[len];
//         for (int i = 0; i <= n - len; ++i) {
//             for (int j = 0; j < len; ++j) {
//                 window[j] = nums[i + j];
//             }
//             int hcf = window[0];
//             for (int j = 1; j < len && hcf > 1; ++j)
//                 hcf = gcd(hcf, window[j]);
//             if (hcf >= 2) {
//                 changesNeeded++;
//                 if (changesNeeded > maxC) {
//                     return false;
//                 }
//                 // Block further overlap
//                 i += len - 1;
//             }
//         }
//         return true;
//     }
// }

// TC = O(n log n)
// SC = O(n log n)

class Solution {
    // Precompute Sparse Table for GCD
    private int[][] st;
    private int[] log2;

    public int minStable(int[] nums, int maxC) {
        int n = nums.length;

        // Preprocess sparse table
        buildSparseTable(nums);

        int left = 1, right = n, ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (canReduce(nums, mid, maxC)) {
                right = mid - 1;
            } else {
                ans = mid;
                left = mid + 1;
            }
        }
        return ans;
    }

    // Precompute Sparse Table for GCD queries
    private void buildSparseTable(int[] nums) {
        int n = nums.length;
        int K = 32 - Integer.numberOfLeadingZeros(n);
        st = new int[n][K + 1];
        log2 = new int[n + 1];
        for (int i = 2; i <= n; i++) log2[i] = log2[i / 2] + 1;
        for (int i = 0; i < n; i++) st[i][0] = nums[i];
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    // GCD query for range [l, r]
    private int rangeGCD(int l, int r) {
        int j = log2[r - l + 1];
        return gcd(st[l][j], st[r - (1 << j) + 1][j]);
    }

    // Greedy check using the sparse table
    private boolean canReduce(int[] nums, int len, int maxC) {
        int n = nums.length;
        int changesNeeded = 0;
        int i = 0;
        while (i <= n - len) {
            int hcf = rangeGCD(i, i + len - 1);
            if (hcf >= 2) {
                changesNeeded++;
                if (changesNeeded > maxC) {
                    return false;
                }
                // Block overlap
                i += len;
            } else {
                i++;
            }
        }
        return true;
    }

    // Helper function to calculate GCD (Euclidean)
    private int gcd(int a, int b) {
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
}