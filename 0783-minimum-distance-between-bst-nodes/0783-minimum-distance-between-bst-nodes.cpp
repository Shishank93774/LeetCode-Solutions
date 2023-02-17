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
    int maxToLeft(TreeNode* root){
        if(root == NULL) return -1;
        while(root->right != NULL){
            root = root->right;
        }
        return root->val;
    }
    int minToRight(TreeNode* root){
        if(root == NULL) return INT_MAX;
        while(root->left != NULL){
            root = root->left;
        }
        return root->val;
    }
    void helper(TreeNode* root, int &ans){
        if(root == NULL) return;
        if(root->left){
            int mxToLeft = maxToLeft(root->left);
            ans = min(ans, root->val - mxToLeft);
        }
        if(root->right){
            int mnToRit = minToRight(root->right);
            ans = min(ans, mnToRit - root->val);
        }
        helper(root->left, ans), helper(root->right, ans);
    }
public:
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        helper(root, ans);
        return ans;
    }
};