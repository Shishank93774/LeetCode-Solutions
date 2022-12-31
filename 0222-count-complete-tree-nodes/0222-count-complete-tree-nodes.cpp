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
int ans;
class Solution {
    int height(TreeNode *root){
        if(root == NULL) return 0;
        int h = 1;
        while(root->left){
            root = root->left; h++;
        }
        return h;
    }
public:
    int countNodes(TreeNode* root, int cur = 1) {
        ans = 0;
        if(root == NULL) return 0;
        int lh = height(root->left), rh = height(root->right);
        if(rh == 0)
            if(root->left != NULL) ans = cur*2;
            else ans = cur;
        else
            if(lh == rh) countNodes(root->right, cur*2 + 1);
            else countNodes(root->left, cur*2);
        
        return ans;
    }
};