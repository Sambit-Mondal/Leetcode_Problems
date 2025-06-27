// 21. Merge Two Sorted Lists (https://leetcode.com/problems/merge-two-sorted-lists/)

// TC = O(n)
// SC = O(1)

class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {

        // Initialise a dummy node and set it as the current node
        ListNode dummyNode = new ListNode();
        ListNode current = dummyNode;
        
        while (list1 != null && list2 != null) {
            // If current node value of list1 is larger than list2
            if (list1.val > list2.val) {
                current.next = list2;
                list2 = list2.next;

            // If current node value of list2 is larger than list1
            } else {
                current.next = list1;
                list1 = list1.next;
            }

            // Move the pointer to the next node
            current = current.next;
        }

        // Append the remaining nodes (if any) to the end of the list
        current.next = (list1 != null) ? list1 : list2;

        return dummyNode.next;
    }
}