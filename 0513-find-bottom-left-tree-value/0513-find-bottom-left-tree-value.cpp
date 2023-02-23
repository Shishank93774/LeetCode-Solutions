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
int val, mxR;
class Solution {
    void helper(TreeNode* root, int row){
        if(root == NULL) return;
        if(mxR < row) {val = root->val; mxR = row;}
        helper(root->left, row+1);
        helper(root->right, row+1);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        mxR = -1;
        helper(root, 0);
        return val;
    }
};