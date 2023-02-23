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
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode *> qu;
        vector<int> ans;
        qu.push(root);
        while(!qu.empty()){
            int sz = qu.size();
            ans.push_back(qu.front()->val);
            while(sz--){
                TreeNode *cur = qu.front(); qu.pop();
                if(cur->right) qu.push(cur->right);
                if(cur->left) qu.push(cur->left);
            }
        }
        return ans;
    }
};