// Hexadecimal and Hexatrigesimal Conversion (https://leetcode.com/problems/hexadecimal-and-hexatrigesimal-conversion/)
// Biweekly Contest 160

// TC = O(1)
// SC = O(1)

class Solution {
    public String concatHex36(int n) {
        
        // Hexadecimal representation
        int n2 = n * n;

        // Hexatrigesimal representation
        int n3 = n * n * n;

        // Convert n2 to hexadecimal in uppercase
        String hex = Integer.toHexString(n2).toUpperCase();

        // Convert n3 to base-36 in uppercase
        String base36 = Integer.toString(n3, 36).toUpperCase();

        // Concatenate
        String concat = hex + base36;

        return concat;
    }
}