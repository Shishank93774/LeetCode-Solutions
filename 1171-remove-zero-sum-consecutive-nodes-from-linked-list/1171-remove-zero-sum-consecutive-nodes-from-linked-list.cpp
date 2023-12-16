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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0), *cur = dummy;
        dummy->next = head;
        int sum = 0;
        unordered_map<int, ListNode*> mp;
        while (cur) {
            sum += cur->val;
            if (mp.count(sum)) {
                cur =  mp[sum]->next;
                int tsum = sum + cur->val;
                while (tsum != sum) {
                    mp.erase(tsum);
                    cur = cur->next;
                    tsum += cur->val;
                }
                mp[sum]->next = cur->next;
            } else {
                mp[sum] = cur;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};