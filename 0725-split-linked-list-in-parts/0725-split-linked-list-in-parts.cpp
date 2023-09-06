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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        ListNode *ptr = head;
        while(ptr){
            length++;
            ptr = ptr->next;
        }
        int d = length/k;
        int r = length%k;
        vector<ListNode*> ans;
        ptr = head;
        while(k--){
            int cur = d + (r>0);
            ListNode *curListHead = NULL, *curListTail = NULL;
            while(ptr and cur--){
                if(curListHead == NULL){
                    curListHead = ptr;
                }else{
                    curListTail->next = ptr;
                }
                curListTail = ptr;
                ptr = ptr->next;
            }
            if(curListTail) curListTail->next = NULL;
            ans.push_back(curListHead);
            r--;
        }
        return ans;
    }
};