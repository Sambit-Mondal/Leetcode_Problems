// 74. Search a 2D Matrix (https://leetcode.com/problems/search-a-2d-matrix/)

class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        // Using loops
        // TC = O(m * n)
        // SC = O(1)
        // for (int i = 0; i < matrix.length; i++) {
        //     for (int j = 0; j < matrix[i].length; j++) {
        //         if (matrix[i][j] == target) {
        //             return true;
        //         }
        //     }
        // }

        // return false;


        // Using Binary Search
        // TC = O(m + n)
        // SC = O(1)
        int rows = matrix.length;
        int cols = matrix[0].length;
        int row = 0;
        int col = cols - 1;

        while (row < rows && col > -1) {
            int currentElement = matrix[row][col];

            if (currentElement == target) {
                return true;
            } else if (currentElement < target) {
                row++;
            } else {
                col--;
            }
        }

        return false;
    }
}