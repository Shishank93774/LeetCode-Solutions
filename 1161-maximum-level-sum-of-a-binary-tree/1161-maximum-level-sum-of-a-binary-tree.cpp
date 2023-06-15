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
    int maxLevelSum(TreeNode* root) {
        int mx = -2e9, ans = 0;
        queue<TreeNode* > qu;
        qu.push(root);
        int d = 0;
        while(!qu.empty()){
            int sz = qu.size();
            int sum = 0;
            while(sz--){
                auto f = qu.front(); qu.pop();
                sum += f->val;
                if(f->left) qu.push(f->left);
                if(f->right) qu.push(f->right);
            }
            d++;
            if(sum > mx){
                mx = sum;
                ans = d;
            }
        }
        return ans;
    }
};