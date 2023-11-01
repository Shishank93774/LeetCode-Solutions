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
    unordered_map<int, int> mp;
    void dfs(TreeNode *root){
        if(root == NULL) return;
        mp[root->val]++;
        dfs(root->left), dfs(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        mp.clear();
        dfs(root);
        vector<int> ans;
        int mx = 0;
        for(auto it: mp){
            if(it.second > mx){
                ans.clear();
                ans.push_back(it.first);
            }else if(it.second == mx){
                ans.push_back(it.first);
            }
            mx = max(mx, it.second);
        }
        return ans;
    }
};