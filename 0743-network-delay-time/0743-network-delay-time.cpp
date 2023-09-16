class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int> > adj[n];
        for(auto &e: times){
            int u = e[0], v = e[1], w = e[2];
            u--; v--;
            adj[u].push_back({v, w});
        }
        k--;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pqu;
        pqu.push({0, k});
        int ans = -1;
        vector<int> dp(n, 1e9);
        dp[k] = 0;
        while(!pqu.empty()){
            auto [d, u] = pqu.top(); pqu.pop();
            
            for(auto &[v, w]: adj[u]){
                if(dp[v] > (d+w)){
                    dp[v] = d+w;
                    pqu.push({dp[v], v});
                }
            }
        }
        for(int i = 0; i<n; i++){
            ans = max(ans, dp[i]);
        }
        return (ans == 1e9?-1:ans);
    }
};