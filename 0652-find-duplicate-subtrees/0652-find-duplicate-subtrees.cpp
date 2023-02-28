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
    string helper(TreeNode* root, map<string, int> &mp, vector<TreeNode* > &ans){
        if(root == NULL) return "";
        string tmp = to_string(root->val) + "|" + helper(root->left, mp, ans) + "|" + helper(root->right, mp, ans);
        mp[tmp]++;
        if(mp[tmp] == 2) ans.push_back(root);
        return tmp;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string, int> mp;
        vector<TreeNode *> ans;
        helper(root, mp, ans);
        return ans;
    }
};