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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        deque<TreeNode *> dqu; dqu.push_back(root);
        vector<vector<int> > ans;
        bool chk = true;
        while(!dqu.empty()){
            int sz = dqu.size();
            vector<int> temp;
            while(sz-->0){
                TreeNode *f;
                if(chk){
                    f = dqu.front(); dqu.pop_front();
                    if(f == NULL) continue;
                    temp.push_back(f->val);
                    dqu.push_back(f->left);
                    dqu.push_back(f->right);
                }else{
                    f = dqu.back(); dqu.pop_back();
                    if(f == NULL) continue; 
                    temp.push_back(f->val);
                    dqu.push_front(f->right);
                    dqu.push_front(f->left);
                }

            }
            if(temp.size()) ans.push_back(temp);
            chk = !chk;
        }
        return ans;
    }
};