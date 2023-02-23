class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int> > ans;
        vector<int> adj[n];
        int m = connections.size();
        for(int i = 0; i<m; i++){
            int u = connections[i][0], v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> disc(n, 0), low(n, INT_MAX);
        int timer = 0;
        auto dfs = [&](int src, int par, auto &&dfs) -> void {
            int conn = 0;
            disc[src] = low[src] = ++timer;
            for(int nbr: adj[src]){
                if(nbr == par) continue;
                conn++;
                if(disc[nbr]) low[src] = min(low[src], disc[nbr]);
                else{
                    dfs(nbr, src, dfs);
                    low[src] = min(low[src], low[nbr]);
                    if(low[nbr] > disc[src]) ans.push_back({src, nbr});
                }
            }
        };
        for(int i = 0; i<n; i++) if(!disc[i]) dfs(i, -1, dfs);
        return ans;
    }
};