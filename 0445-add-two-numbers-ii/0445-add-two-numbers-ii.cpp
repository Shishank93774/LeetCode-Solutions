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

#define data val

class Solution {
    ListNode* reverseLL(ListNode* head){
        if(head == NULL or head->next == NULL) return head;
        ListNode *cur = head, *prv = NULL, *nxt;
        do{
            nxt = cur->next;
            cur->next = prv;
            prv = cur;
            cur = nxt;
        }while(cur);
        
        return prv;
    }
public:
    ListNode* addTwoNumbers(ListNode* first, ListNode* second) {
        ListNode *head1 = reverseLL(first), *head2 = reverseLL(second);
        int c = 0;
        ListNode *ptr1 = head1, *ptr2 = head2, *head = NULL;
        while(ptr1 and ptr2){
            int sum = ptr1->data + ptr2->data + c;
            ListNode *newNode = new ListNode(sum%10);
            if(head == NULL) head = newNode;
            else{
                newNode->next = head;
                head = newNode;
            }
            c = sum/10;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        while(ptr1){
            int sum = ptr1->data + c;
            ListNode *newNode = new ListNode(sum%10);
            if(head == NULL) head = newNode;
            else{
                newNode->next = head;
                head = newNode;
            }
            c = sum/10;
            ptr1 = ptr1->next;
        }
        while(ptr2){
            int sum = ptr2->data + c;
            ListNode *newNode = new ListNode(sum%10);
            if(head == NULL) head = newNode;
            else{
                newNode->next = head;
                head = newNode;
            }
            c = sum/10;
            ptr2 = ptr2->next;
        }
        if(c){
            ListNode *newNode = new ListNode(1);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};