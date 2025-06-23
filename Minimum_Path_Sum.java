// 64. Minimum Path Sum (https://leetcode.com/problems/minimum-path-sum/)

// TC = O(m * n)
// SC = O(m * n)

class Solution {
    public int minPathSum(int[][] grid) {

        // Initialise the variables for row and column
        int rows = grid.length;
        int cols = grid[0].length;

        // Create a 2D array to store the minimum path sums for each cell
        int[][] minDistance = new int[rows][cols];

        // Initialize all cells with a very large value (since we are looking for minimum)
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                minDistance[i][j] = Integer.MAX_VALUE;
            }
        }

        // Starting point
        minDistance[0][0] = grid[0][0];

        // Fill the minDistance table
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                // Move right
                if (j + 1 < cols) {
                    minDistance[i][j + 1] = Math.min(minDistance[i][j + 1], minDistance[i][j] + grid[i][j + 1]);
                }

                // Move down
                if (i + 1 < rows) {
                    minDistance[i + 1][j] = Math.min(minDistance[i + 1][j], minDistance[i][j] + grid[i + 1][j]);
                }
            }
        }

        // Return the minimum path sum
        return minDistance[rows - 1][cols - 1];
    }
}