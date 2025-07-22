class Solution {
    public int singleNumber(int[] nums) {

        // Using HashMap

        // TC = O(n)
        // SC = O(n)

        // Map<Integer, Integer> numMap = new HashMap<>();

        // for (int num : nums) {
        //     numMap.put(num, numMap.getOrDefault(num, 0) + 1);
        // }

        // for (Map.Entry<Integer, Integer> entry : numMap.entrySet()) {
        //     if (entry.getValue() == 1) {
        //         return entry.getKey();
        //     }
        // }

        // return -1;


        // Using XOR

        // TC = O(n)
        // SC = O(1)

        int result = 0;

        for (int num : nums) {
            result ^= num;
        }

        return result;
    }
}