/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // The slow and fast pointers have "met," indicating a cycle
                
                // Move one of the pointers back to the head of the list
                slow = head;
                // Advance both pointers one node at a time until they meet again
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                // The node at which they meet is the starting point of the cycle
                return slow;
            }
        }
        
        // The fast pointer reached the end of the list, indicating no cycle
        return NULL;
        }
};