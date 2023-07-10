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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0; // Check
        int ans = 1;
        queue<TreeNode* > qu;
        qu.push(root);
        while(!qu.empty()){
            bool chk = true;
            int sz = qu.size();
            while(sz--){                
                auto f = qu.front(); qu.pop();
                if(f->left == NULL and f->right == NULL) {chk = false; break;} //Leaf Node
                if(f->left) qu.push(f->left);
                if(f->right) qu.push(f->right);
            }
            if(!chk) break;
            ans++;
        }
        return ans;
    }
};