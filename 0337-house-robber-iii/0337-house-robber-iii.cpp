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
    array<int, 2> dfs(TreeNode *root){ // no-take, take
        if(root == NULL) return {0, 0};
        
        auto l = dfs(root->left), r = dfs(root->right);
        
        int a1 = root->val + l[0] + r[0];
        int a2 = max(l[0], l[1]) + max(r[0], r[1]);
        return {a2, a1};
    }
public:
    int rob(TreeNode* root) {
        auto v = dfs(root);
        return max(v[0], v[1]);
    }
};