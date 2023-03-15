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
//     int getHeight(TreeNode* root){
//         if(root == NULL) return 0;
//         int ans = 1 + max(getHeight(root->left), getHeight(root->right));
//         return ans;
//     }
//     bool helper(TreeNode* root, int curH, const int maxH){
//         if(root == NULL) return true;
//         if(curH == maxH - 1){
//             if(!root->left and !root->right) return true;
//             if(!root->left and root->right) return false;
            
//         }else{
//             if(!root->left and !root->right) return true;
//             if(root->left and root->right) return (helper(root->left, curH+1, maxH) && helper(root->right, curH+1, maxH));
//             return false;
//         }
//         return true;
//     }
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode *> qu;
        qu.push(root);
        bool chk = false;
        while(!qu.empty()){
            int sz = qu.size();
            while(sz--){
                TreeNode* f = qu.front(); qu.pop();
                if(chk and f) return false;
                if(f == NULL) {chk = true; continue;}
                qu.push(f->left);
                qu.push(f->right);
            }
        }
        return true;
    }
};