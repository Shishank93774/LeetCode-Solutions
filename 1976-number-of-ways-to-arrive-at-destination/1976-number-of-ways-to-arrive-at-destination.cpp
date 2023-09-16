const int mod = 1e9+7;
#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, ll> > adj[n];
        for(auto &r: roads){
            int u = r[0], v = r[1], w = r[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<ll> dp(n, 1e18);
        vector<int> cnt(n, 0);
        
        priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int>> > pqu;
        
        pqu.push({0, 0});
        dp[0] = 0;
        cnt[0] = 1;
        
        while(!pqu.empty()){
            auto f = pqu.top(); pqu.pop();
            
            ll d = f.first;
            int u = f.second;
                        
            for(auto &[v, w]: adj[u]){
                if(dp[v] > d + w){
                    dp[v] = d + w;
                    cnt[v] = cnt[u];
                    pqu.push({dp[v], v});
                }else if(dp[v] == d+w){
                    cnt[v] += cnt[u];
                    cnt[v] %= mod;
                }
            }
        }
        return cnt[n-1];       
    }
};