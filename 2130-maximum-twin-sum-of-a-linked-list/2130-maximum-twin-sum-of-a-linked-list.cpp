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
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *nextNode, *prev = NULL;
        while(slow){
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }
        
        int ans = 0;
        ListNode *start = head;
        while(prev){
            ans = max(ans, start->val + prev->val);
            start = start->next;
            prev = prev->next;
        }
        
        return ans;
    }
};