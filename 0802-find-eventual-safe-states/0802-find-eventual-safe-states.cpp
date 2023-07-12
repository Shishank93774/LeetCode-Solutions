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
    
    void dfs2(int src, vector<vector<int> > &adj, vector<int> &indeg, vector<bool> &vis, vector<int> &safeNodes){
        if(vis[src]) return;
        vis[src] = true;
        safeNodes.push_back(src);
        for(int nbr: adj[src]){
            indeg[nbr]--;
            if(indeg[nbr] == 0) dfs2(nbr, adj, indeg, vis, safeNodes);
        }
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        vector<int> safeNodes;
        int n = adj.size();
        
        vector<vector<int> > revAdj(n);
        vector<int> indeg(n, 0);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<adj[i].size(); j++){
                revAdj[adj[i][j]].push_back(i);
                indeg[i]++;
            }
        }
        vector<bool> vis(n, false);
       for(int i = 0; i<n; i++){
            if(indeg[i] == 0){
                dfs2(i, revAdj, indeg, vis, safeNodes);
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
        
        // vector<bool> marker(n, false);
        // for(int src = 0; src<n; src++){
        //     if(!vis[src]) dfs(src, -1, adj, vis, marker);
        //     if(marker[src]) safeNodes.push_back(src);
        // }
        // return safeNodes;
    }
};