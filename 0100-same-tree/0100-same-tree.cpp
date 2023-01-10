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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL and q == NULL) return true;
        if(p == NULL or q == NULL) return false;
        bool chk = false;
        if(p->val == q->val){
            chk = true;
            chk &= isSameTree(p->left, q->left);
            chk &= isSameTree(p->right, q->right);
        }
        return chk;
    }
};