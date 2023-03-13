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
    int areMirror(TreeNode* a, TreeNode* b) {
    // Your code here
        if(a == NULL and b == NULL) return true;
        if(a == NULL or b == NULL) return false;
        bool chk = areMirror(a->left, b->right) & areMirror(a->right, b->left);
        chk &= (a->val == b->val);
        return chk;
    }
public:
    bool isSymmetric(TreeNode* root) {
       return areMirror(root->left, root->right); 
    }
};