class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        
        int n = adj.size();
        vector<int> vis(n, 0);
        auto dfs = [&](int src, int color, auto&& dfs)->bool{
            if(vis[src]) return true;
            vis[src] = color;
            for(int nbr: adj[src]){
                if(vis[nbr] == color) return false;
                if(vis[nbr]) continue;
                bool chk = dfs(nbr, (color^3), dfs);
                if(!chk) return false;
            }
            return true;
        };
        
        for(int i = 0; i<n; i++) if(!dfs(i, 1, dfs)) return false;
        return true;
    }
};