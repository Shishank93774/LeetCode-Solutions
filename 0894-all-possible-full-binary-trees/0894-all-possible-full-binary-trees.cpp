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
unordered_map<int, vector<TreeNode*> > mp;
class Solution {
    vector<TreeNode *> dfs(int n){
        if(n%2 == 0) return {};        
        if(mp.find(n) != mp.end()) return mp[n];
        
        if(n == 1) return mp[1] = {new TreeNode(0)};
        
        vector<TreeNode *> ans;
        for(int l = 1; l<n; l+=2){
            vector<TreeNode *> lh = dfs(l);
            vector<TreeNode *> rh = dfs(n-l-1);
            for(auto ll: lh){
                for(auto rr: rh){
                    TreeNode *root = new TreeNode(0, ll, rr);
                    ans.push_back(root);
                }
            }
        }
        return mp[n] = ans;
    }
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2 == 0) return {};
        return dfs(n);
        
    }
};