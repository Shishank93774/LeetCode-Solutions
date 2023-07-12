class Solution {
    bool dfs(int src, int par, vector<vector<int> > &adj, vector<bool> &vis
             , vector<bool> &marker){
        vis[src] = true;
        marker[src] = false;
        bool safe = true;
        for(int nbr: adj[src]){
            if(vis[nbr])
                safe = safe && marker[nbr];
            else
                safe = safe && (dfs(nbr, src, adj, vis, marker));
            if(!safe) return false;
        }
        marker[src] = safe;
        return safe;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        vector<int> safeNodes;
        int n = adj.size();
        vector<bool> marker(n, false);
        vector<bool> vis(n, false);
        for(int src = 0; src<n; src++){
            if(!vis[src]) dfs(src, -1, adj, vis, marker);
            if(marker[src]) safeNodes.push_back(src);
        }
        return safeNodes;
    }
};