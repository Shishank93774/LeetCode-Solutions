/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define Node TreeNode
#define data val


class Solution {
    set<int> st;
    bool nodeToRootPath(Node *root, int tar, vector<Node *> &path){
         if(root == NULL) return false;
         if(root->data == tar){
             path.push_back(root);
             st.insert(root->data);
             return true;
         }
         bool inL = nodeToRootPath(root->left, tar, path);
         if(inL){
             path.push_back(root);
             st.insert(root->data);
             return true;
         }
         bool inR = nodeToRootPath(root->right, tar, path);
         if(inR){
             path.push_back(root);
             st.insert(root->data);
             return true;
         }
         return false;
    }
    void kDistanceDown(Node *root, int cur, int k, vector<int> &ans){
         if(root == NULL) return;
         if(st.count(root->data)) return;
         if(cur == k){
             ans.push_back(root->data);
         }
         kDistanceDown(root->left, cur+1, k, ans);
         kDistanceDown(root->right, cur+1, k, ans);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         vector<Node *> path;
        st.clear();
        nodeToRootPath(root, target->data, path);
        // for(auto nd: path)
        vector<int> ans;
        for(auto nd: path){
            if(k >= 1){
                kDistanceDown(nd->left, 1, k, ans);
                kDistanceDown(nd->right, 1, k, ans);
            }else{
                ans.push_back(nd->data);
                break;
            }
            k--;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};