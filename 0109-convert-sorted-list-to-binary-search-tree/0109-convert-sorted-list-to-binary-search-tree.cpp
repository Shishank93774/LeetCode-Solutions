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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// unordered_map<int, ListNode *> arr;
class Solution {
    TreeNode* helper(ListNode *head, ListNode *tail){
        if(head == tail) return NULL;
        if(head->next == tail) return new TreeNode(head->val);
        ListNode *slow = head, *fast = head;
        while(fast != tail and fast->next != tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        return new TreeNode(slow->val, helper(head, slow), helper(slow->next, tail));
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // arr.clear();
        // int i = 0;
        // while(head != NULL){
        //     arr[i++] = head;
        //     head = head->next;
        // }
        return helper(head, NULL);
    }
};