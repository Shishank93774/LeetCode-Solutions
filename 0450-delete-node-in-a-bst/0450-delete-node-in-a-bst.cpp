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
    TreeNode* deleteNode(TreeNode* root, int x) {
        if(root == NULL) return NULL;
        if(root->val > x){
            root->left = deleteNode(root->left, x);
        }else if(root->val < x){
            root->right = deleteNode(root->right, x);
        }else{
            if(root->right == NULL) return root->left;
            else{
                TreeNode *n = root->right;
                while(n->left) n = n->left;
                swap(n->val, root->val);
                root->right = deleteNode(root->right, x);
            }
        }
        return root;
    }
};