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
    vector<int> ans;
    int mx = 0, cur = 0, val = 0;
    void dfs(TreeNode *root){
        if(root == NULL) return;
        
        dfs(root->left);
        
        int rv = root->val;
        if(rv == val){
            cur++;
        }else{
            cur = 1;
            val = rv;
        }
        
        if(cur > mx){
            ans.clear();
            ans.push_back(val);
            mx = cur;
        }else if(cur == mx){
            ans.push_back(val);
        }
        
        dfs(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }
};