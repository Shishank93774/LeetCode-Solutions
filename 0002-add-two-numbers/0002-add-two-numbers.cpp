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
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        ListNode *head = NULL, *tail = NULL;
        int c = 0;
        while(head1 and head2){
            int x = head1->val;
            int y = head2->val;
            int s = x+y+c;
            int v = s%10;
            c = s>9;
            ListNode *temp = new ListNode(v);
            if(!tail){ tail = temp; head = temp;}
            else tail->next = temp;
            tail = temp;
            head1 = head1->next;
            head2 = head2->next;
        }
        while(head1){
            int x = head1->val;
            int s = x+c;
            int v = s%10;
            c = s>9;
            ListNode *temp = new ListNode(v);
            if(!tail){ tail = temp; head = temp;}
            else tail->next = temp;
            tail = temp;
            head1 = head1->next;
        }
        while(head2){
            int x = head2->val;
            int s = x+c;
            int v = s%10;
            c = s>9;
            ListNode *temp = new ListNode(v);
            if(!tail){ tail = temp; head = temp;}
            else tail->next = temp;
            tail = temp;
            head2 = head2->next;
        }
        if(c){
            ListNode *temp = new ListNode(c);
            if(!tail){ tail = temp; head = temp;}
            else tail->next = temp;
            tail = temp;
        }
        return head;
    }
};