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
class Solution {
    TreeNode* helper(unordered_map<int, ListNode *> &arr, int l, int r){
        if(l > r) return NULL;
        if(l==r) return new TreeNode(arr[l]->val, NULL, NULL);
        int mid = l + (r - l)/2;
        return new TreeNode(arr[mid]->val, helper(arr, l, mid - 1), helper(arr, mid + 1, r));
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        unordered_map<int, ListNode *> arr;
        int i = 0;
        while(head != NULL){
            arr[i++] = head;
            head = head->next;
        }
        return helper(arr, 0, arr.size() - 1);
    }
};