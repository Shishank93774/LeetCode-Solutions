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
    int pseudoPalindromicPaths (TreeNode* root, vector<int> cnt = vector<int>(10, 0)) {
        cnt[root->val-1]++;
        if(root->left == NULL and root->right == NULL){
            int cnto = 0;
            for(int i = 0; i<10; i++){
                cnto += (cnt[i]&1);
            }
            return cnto <= 1;
        }
        int ans = 0;
        if(root->left) ans += pseudoPalindromicPaths(root->left, cnt);
        if(root->right) ans += pseudoPalindromicPaths(root->right, cnt);
        
        return ans;
    }
};