// 9. Palindrome Number (https://leetcode.com/problems/palindrome-number/)

// TC = O(log x)
// SC = O(1)

class Solution {
    public boolean isPalindrome(int x) {
        
        // Negative integers can't be palindrome
        if (x < 0) {
            return false;
        }

        // Initialise variables
        int reverseNum = 0;
        int num = x;

        // Reverse the number
        while (num != 0) {
            reverseNum = reverseNum * 10 + num % 10;
            num = num / 10;
        }

        // If rev = x, return true, else false
        return (reverseNum == x);
    }
}