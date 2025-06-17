// 2942. Find Words Containing Character (https://leetcode.com/problems/find-words-containing-character/)

import java.util.*;

class Find_Words_Containing_Character {
    public List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> answer = new ArrayList<>();

        for (int i = 0; i < words.length; i++) {
            for (char ch : words[i].toCharArray()) {
                if (ch == x) {
                    answer.add(i);
                    break;
                }
            }
        }

        return answer;
    }
}