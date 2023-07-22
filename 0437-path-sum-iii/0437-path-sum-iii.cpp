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
    unordered_map<long long, int> mp;
    int ans;
    void dfs(TreeNode* root, int x, long long sum){
        if(root == NULL) return;
        
        sum += root->val;
        ans += mp[sum - x];
        mp[sum]++;
            dfs(root->left, x, sum);
            dfs(root->right, x, sum);
        mp[sum]--;
    }
public:
    int pathSum(TreeNode* root, int x) {
        if(root == NULL) return 0;
        ans = 0;
        mp.clear();
        mp[0]++;
        dfs(root, x, 0);
        return ans;
    }
};