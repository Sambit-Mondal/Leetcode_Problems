// 206. Reverse Linked List (https://leetcode.com/problems/reverse-linked-list/)

// TC = O(n)
// SC = O(1)

class Solution {
    public ListNode reverseList(ListNode head) {
        // Initialise three pointers
        ListNode prev = null; // To track the prev node of the current
        ListNode next = null; // To track the next node of the current
        ListNode current = head; // To track the current node

        while (current != null) {
            // Store the next node in the list (to change the current node's link)
            next = current.next;

            // Reverse the link
            current.next = prev;

            // Update prev node as current
            prev = current;

            // Update current node as next
            current = next;
        }

        return prev;
    }
}