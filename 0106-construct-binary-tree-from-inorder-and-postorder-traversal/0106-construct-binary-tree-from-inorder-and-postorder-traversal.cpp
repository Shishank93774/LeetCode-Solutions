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
unordered_map<int, int> mp;
class Solution {
    TreeNode* helper(const vector<int> &inorder, const vector<int> &postorder, int &rootIdx, int l, int r){
        if(l > r) return NULL;
        TreeNode* root = new TreeNode(postorder[rootIdx]);
        int p = mp[postorder[rootIdx]];
        rootIdx--;
        root->right = helper(inorder, postorder, rootIdx, p+1, r);
        root->left = helper(inorder, postorder, rootIdx, l, p-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        mp.clear();
        for(int i = 0; i<inorder.size(); i++) mp[inorder[i]] = i;
        int rootIdx = postorder.size() - 1;
        return helper(inorder, postorder, rootIdx, 0, inorder.size() - 1);
    }
};