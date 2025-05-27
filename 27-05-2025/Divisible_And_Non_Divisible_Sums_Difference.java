// 2894. Divisible and Non-Divisible Sums Difference (https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/)

class Divisible_And_Non_Divisible_Sums_Difference {
  int differenceOfSums(int n, int m) {
    // Brute Force
    // int num1 = 0, num2 = 0;
    // for(int i = 1 ; i <= n ; i++){
    //     if (i % m != 0) {
    //         num1 += i;
    //     }
    //     else {
    //         num2 +=i;
    //     }
    // }
    // return num1 - num2;



    // Optimised Approach
    int totalSum = n * (n + 1) / 2;
    int divisibleCount = n / m;
    int divisibleSum = m * divisibleCount * (divisibleCount + 1) / 2;
    return totalSum - 2 * divisibleSum;
  }
}