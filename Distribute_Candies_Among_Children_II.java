// 2929. Distribute Candies Among Children II (https://leetcode.com/problems/distribute-candies-among-children-ii/)

class Distribute_Candies_Among_Children_II {
    public long distributeCandies(int n, int limit) {
        return (
            cal(n + 2) -
            3 * cal(n - limit + 1) +
            3 * cal(n - (limit + 1) * 2 + 2) -
            cal(n - 3 * (limit + 1) + 2)
        );
    }

    public long cal(int x) {
        if (x < 0) {
            return 0;
        }
        return ((long) x * (x - 1)) / 2;
    }
}