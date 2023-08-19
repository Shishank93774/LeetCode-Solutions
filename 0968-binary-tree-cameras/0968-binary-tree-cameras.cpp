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
map<TreeNode *, int> mp;
int dp[2001][2][2];
class Solution {
    int rec(TreeNode* root, bool watching = false, bool forced = false){
        if(root == NULL){
            if(forced) return 1e9;
            return 0;
        }
        if(root->left == NULL and root->right == NULL) return !watching;
        
        int idx = mp[root];

        if(dp[idx][watching][forced] != -1) return dp[idx][watching][forced];
        
        int ans = 1e9;
        if(forced){
            ans = 1 + rec(root->left, true) + rec(root->right, true);
        }else{
            if(watching){
                ans = rec(root->left, false) + rec(root->right, false);
                ans = min(ans, 1 + rec(root->left, true) + rec(root->right, true));
            }else{
                ans = 1 + rec(root->left, true) + rec(root->right, true);
                int forceLeft = 0 + rec(root->left, false, true) + rec(root->right, false);
                int forceRight = 0 + rec(root->left, false) + rec(root->right, false, true);
                ans = min({ans, forceLeft, forceRight});
            }
        }
        
        return dp[idx][watching][forced] = ans;
    }
public:
    int minCameraCover(TreeNode* root) {
        memset(dp, -1, sizeof dp);
        mp.clear();
        int idx = 0;
        auto dfs = [&](TreeNode *src, auto &&dfs)->void{
            if(src == NULL) return;
            if(src->left == NULL and src->right == NULL){
                mp[src] = idx++;
                return;
            }
            mp[src] = idx++;
            dfs(src->left, dfs), dfs(src->right, dfs);
        };
        dfs(root, dfs);
        
        return rec(root);
    }
};