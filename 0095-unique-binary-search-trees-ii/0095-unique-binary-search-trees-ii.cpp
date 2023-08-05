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
bool done = false;
vector<TreeNode *> ans[9];
TreeNode* insertNode(TreeNode *root, int v){
    if(root == NULL) return new TreeNode(v);
    if(root->val < v){
        root->right = insertNode(root->right, v);
    }else{
        root->left = insertNode(root->left, v);
    }
    return root;
}
TreeNode* buildTree(vector<int> &arr){
    TreeNode *root = NULL;
    for(int x: arr) root = insertNode(root, x);
    
    return root;
}
class Solution {
    string traversal(TreeNode *root){
        if(root == NULL) return "$";
        string ans = "(" + traversal(root->left) + to_string(root->val) + "|" + traversal(root->right) + ")";
        return ans;
    }
    void pre(){
        for(int n = 1; n<=8; n++){
            vector<int> arr(n);
            for(int i = 0; i<n; i++) arr[i] = i+1;
            
            unordered_set<string> st;
            do{
                TreeNode *root = buildTree(arr);
                string hash = traversal(root);
                if(st.find(hash) == st.end()) ans[n].push_back(root);
                st.insert(hash);
            }while(next_permutation(arr.begin(), arr.end()));
        }
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if(!done){
            pre();
            done = true;
        }
        return ans[n];
    }
};