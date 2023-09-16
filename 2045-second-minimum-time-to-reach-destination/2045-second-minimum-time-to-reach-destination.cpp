class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
        vector<int> adj[n+1];
        for(auto &e: edges){
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pqu;
        vector<vector<int> > dp(n+1, {(int)1e9, (int)1e9+1});
        
        pqu.push({0, 1});
        dp[1][0] = 0;
        
        while(!pqu.empty()){
            auto f = pqu.top(); pqu.pop();
            int d = f.first, u = f.second;
            
            int div = d/change;
            if(div%2){ // red
                d += (change - d%change);
            }
            
            for(int v: adj[u]){
                if(dp[v][1] > (d + time)){
                    if(dp[v][0] > (d + time)){ // min
                        dp[v][1] = dp[v][0];
                        dp[v][0] = (d + time);
                        pqu.push({dp[v][0], v});
                    }else if(dp[v][0] == (d + time)){ // skip                        
                    }else{ // secMin
                        dp[v][1] = (d + time);
                        pqu.push({dp[v][1], v});
                    }
                }
            }
            
        }
        
        return dp[n][1];
    }
};