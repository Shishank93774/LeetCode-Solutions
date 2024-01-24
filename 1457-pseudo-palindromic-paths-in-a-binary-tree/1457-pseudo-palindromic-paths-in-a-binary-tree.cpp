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

auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();

class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root, int mask = 0) {
        mask ^= (1<<root->val);
        if(root->left == NULL and root->right == NULL){
            int cnto = 0;
            for(int i = 1; i<=10; i++){
                cnto += ((mask>>i)&1);
            }
            return cnto <= 1;
        }
        int ans = 0;
        if(root->left) ans += pseudoPalindromicPaths(root->left, mask);
        if(root->right) ans += pseudoPalindromicPaths(root->right, mask);
        
        return ans;
    }
};