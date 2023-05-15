/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *p1 = head;
        k--;
        while(k--){
            p1 = p1->next;
        }
        
        ListNode *slow = head, *fast = p1->next;
        while(fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        swap(slow->val, p1->val);
        return head;
    }
};