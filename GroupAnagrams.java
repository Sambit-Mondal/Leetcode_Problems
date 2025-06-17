// 49. Group Anagrams (https://leetcode.com/problems/group-anagrams/)

import java.util.*;

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        
        // Declaration of a HashMap
        Map<String, List<String>> strMap = new HashMap<>();

        // Traversing through the array strs
        for (String str : strs) {

            // Converting each string to a character array
            char[] chars = str.toCharArray();

            // Sorting the character array
            Arrays.sort(chars);

            // Storing the previous string, after sorting, to the variable 'key'
            String key = new String(chars);

            // Storing the key and it's anagrams as key-value pair in the HashMap
            if (!strMap.containsKey(key)) {
                strMap.put(key, new ArrayList<>());
            }
            strMap.get(key).add(str);
        }

        // Returning the value of the HashMap
        return new ArrayList<>(strMap.values());
    }
}