class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        
        vector<pair<int, int> > adj[n];
        
        for(auto &e: edges){
            int u = e[0], v = e[1];
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }
        
        vector<int> ans(n, 0);
        map<pair<int, int>, int > dp;
        
        auto dfs = [&](int src, int par, auto &&dfs)->int{
            
            if(dp.find({src, par}) != dp.end()) return dp[{src, par}];
            
            int a = 0;
            for(auto &[v, w]: adj[src]){
                if(v == par) continue;
                a += w;
                a += dfs(v, src, dfs);
            }
            
            return dp[{src, par}] = a;
        };
        
        for(int i = 0; i<n; i++){
            ans[i] = dfs(i, -1, dfs);
        }
        
        return ans;
        
    }
};