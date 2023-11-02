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
    vector<int> dfs(TreeNode *root){ // sum, cnt, ans
        if(root == NULL) return {0, 0, 0};
        
        vector<int> lh = dfs(root->left), rh = dfs(root->right);
        
        int v = root->val;
        
        int subTreeSum = lh[0] + rh[0] + v;
        int subTreeCnt = lh[1] + rh[1] + 1;
        int ansSoFar = lh[2] + rh[2];
        
        if(subTreeSum/subTreeCnt == v) ansSoFar++;
        
        return {subTreeSum, subTreeCnt, ansSoFar};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        if(root == NULL) return 0;
        
        return dfs(root)[2];
    }
};