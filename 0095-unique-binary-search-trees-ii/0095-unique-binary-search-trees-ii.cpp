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
    vector<TreeNode*> generateTrees(int r, int l = 1) {
        vector<TreeNode*> ans;
        if(l > r) return {NULL};
			
		// Consider every number in range [l, r] as root 
        for(int i=l; i<=r; i++) {
			// generate all possible trees in range [l,i)
            for(auto left: generateTrees(i-1, l)) {
                
				// generate all possible trees in range (i,r]
                for(auto right: generateTrees(r, i+1))
				
					// make new trees with i as the root
                    ans.push_back(new TreeNode(i, left, right));
            }
        }
        return ans;
    }
};