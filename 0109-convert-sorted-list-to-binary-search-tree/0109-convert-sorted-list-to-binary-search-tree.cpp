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
unordered_map<int, ListNode *> arr;
class Solution {
    TreeNode* helper(int l, int r){
        if(l > r) return NULL;
        if(l==r) return new TreeNode(arr[l]->val, NULL, NULL);
        int mid = l + (r - l)/2;
        return new TreeNode(arr[mid]->val, helper(l, mid - 1), helper(mid + 1, r));
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        arr.clear();
        int i = 0;
        while(head != NULL){
            arr[i++] = head;
            head = head->next;
        }
        return helper(0, arr.size() - 1);
    }
};