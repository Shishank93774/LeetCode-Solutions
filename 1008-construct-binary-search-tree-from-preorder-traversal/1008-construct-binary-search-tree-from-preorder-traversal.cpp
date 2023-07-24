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
    TreeNode* bstMakeHelper(vector<int> &pre, int l, int r){
        if(l>r) return NULL;
        int i = l+1;
        while(i<=r and pre[l] >= pre[i]) i++;
        return new TreeNode(pre[l], bstMakeHelper(pre, l+1, i-1), bstMakeHelper(pre, i, r));
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstMakeHelper(preorder, 0, preorder.size() - 1);
    }
};