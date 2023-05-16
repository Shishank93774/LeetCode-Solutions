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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;
        ListNode *back = NULL, *f = head, *s = head->next;
        while(true){
            if(back == NULL){
                head = s;
                back = f;
            }else{
                back->next = s;
            }
            f->next = s->next;
            s->next = f;
            back = f;
            if(f->next == NULL or f->next->next == NULL)break;
            s = f->next->next;
            f = f->next;
        }
        return head;
    }
};