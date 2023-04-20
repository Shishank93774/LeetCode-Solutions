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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long> > qu;
        qu.push({root, 0});
        int ans = 1;
        while(!qu.empty()){
            int sz = qu.size();
            int p = 0;
            while(sz--){
                auto pr = qu.front(); qu.pop();
                TreeNode *f = pr.first;
                int d = pr.second;
                if(f){
                    if(p == 0) p = d;
                    else ans = max(ans, d - p + 1);
                    qu.push({f->left, 2ll*d+1});
                    qu.push({f->right, 2ll*d+2});
                }
            }
        }
        return ans;
    }
};