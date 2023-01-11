class Solution {
    int dfs(int src, int par, vector<int> adj[], vector<bool>& hasApple){
        int ans = 0;
        for(int chld: adj[src]){
            if(chld == par) continue;
            int v = dfs(chld, src, adj, hasApple);
            if(hasApple[chld] or v>0){
                ans += v + 2;
            }
        }
        return ans;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        int e = edges.size();
        for(int i = 0; i<e; i++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(0, -1, adj, hasApple);
    }
};