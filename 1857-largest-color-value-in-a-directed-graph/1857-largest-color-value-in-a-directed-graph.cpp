class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(), m = edges.size();
        vector<int> adj[n];
        vector<vector<int> > dp(n, vector<int>(26, 0));
        vector<int> vis(n, 0);
        for(int i = 0; i<m; i++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            if(u == v) return -1;
        }
        
        auto dfs = [&](int src, auto&& dfs) -> int{
            if(vis[src] == 1) return INT_MAX;
            if(vis[src] == 2) return dp[src][colors[src] - 'a'];
            vis[src] = 1;
            for(int nbr: adj[src]){
                int res = dfs(nbr, dfs);
                if(res == INT_MAX) return INT_MAX;
                for(int i = 0; i<26; i++){
                    dp[src][i] = max(dp[src][i], dp[nbr][i]);
                }
            }
            vis[src] = 2;
            return ++dp[src][colors[src] - 'a'];
        };
        
        int ans = 0;
        for(int i = 0; i<n and ans != INT_MAX; i++){
            ans = max(ans, dfs(i, dfs));
        }
        return ans == INT_MAX?-1: ans;
        
    }
};