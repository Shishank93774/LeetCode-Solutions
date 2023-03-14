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
    void helper(TreeNode *root, int sumSoFar, int &ans){
        if(root->left) helper(root->left, sumSoFar*10 + root->val, ans);
        if(root->right) helper(root->right, sumSoFar*10 + root->val, ans);
        if(!root->left and !root->right) ans += sumSoFar*10 + root->val;
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        helper(root, 0, ans);
        return ans;
    }
};