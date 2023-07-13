class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n, 0);
        vector<vector<int> > adj(n);
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }
        vector<bool> vis(n, false);
        vector<int> topoOrder;
        
        auto dfs = [&](int src, auto &&dfs)->void{
            if(vis[src]) return;
            topoOrder.push_back(src);
            vis[src] = true;
            for(int nbr: adj[src]){
                if(vis[nbr]) continue;
                indeg[nbr]--;
                if(indeg[nbr] == 0) dfs(nbr, dfs);
            }
        };
        
        for(int i = 0; i<n; i++) if(indeg[i] == 0) dfs(i, dfs);
        
        return (topoOrder.size() == n);
    }
};