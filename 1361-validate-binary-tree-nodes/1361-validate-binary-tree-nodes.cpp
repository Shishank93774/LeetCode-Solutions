class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indeg(n, 0);
        
        for(int i = 0; i<n; i++){
            if(leftChild[i] != -1) indeg[leftChild[i]]++;
            if(rightChild[i] != -1) indeg[rightChild[i]]++;
        }
        
        vector<bool> vis(n, false);
        
        bool started = false;
        
        auto dfs = [&](int u, int p, auto &&dfs)->bool{
            vis[u] = true;
            if(leftChild[u] != p and leftChild[u] != -1){
                if(vis[leftChild[u]]) return false;
                if(!dfs(leftChild[u], u, dfs)) return false;
            }
            if(rightChild[u] != p and rightChild[u] != -1){
                if(vis[rightChild[u]]) return false;
                if(!dfs(rightChild[u], u, dfs)) return false;
            }
            
            return true;
        };
        
        bool ans = true;
        for(int i = 0; i<n; i++){
            if(vis[i] or indeg[i]) continue;
            if(started) return false;
            started = true;
            ans &= dfs(i, -1, dfs);
        }
        for(int i = 0; i<n; i++) if(!vis[i]) return false;
        if(!started) return false;
        return ans;
    }
};