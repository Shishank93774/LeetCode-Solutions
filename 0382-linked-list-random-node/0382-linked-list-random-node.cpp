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
    ListNode *temp_head;
public:
    Solution(ListNode* head) {
        temp_head = head;
    }
    
    int getRandom() {
        int nodesTillNow = 0;
        ListNode *randomNode = NULL, *head = temp_head;
        while(head != NULL){
            nodesTillNow++;
            int randNum = rand()%nodesTillNow;
            if(randNum == nodesTillNow - 1) randomNode = head;
            head = head->next;
        }
        return randomNode->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */