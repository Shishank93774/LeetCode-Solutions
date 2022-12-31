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
int mx;
class Solution {
    void dfs(TreeNode *root, int mxPrv, int mnPrv){
        if(root == NULL) return;
        mx = max({mx, abs(mxPrv - root->val), abs(mnPrv - root->val)});
        dfs(root->left, max(mxPrv, root->val), min(mnPrv, root->val)), dfs(root->right, max(mxPrv, root->val), min(mnPrv, root->val)); 
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        mx = 0;
        dfs(root, root->val, root->val);
        return mx;
    }
};