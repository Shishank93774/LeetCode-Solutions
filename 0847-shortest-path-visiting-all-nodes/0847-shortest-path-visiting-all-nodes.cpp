class Solution {
public:
    int shortestPathLength(vector<vector<int>>& adj) {
        int n = adj.size();
        
        int full = ((1<<n) - 1);
        
        vector<vector<int> > dp(n, vector<int>(full+1, -1));
        
        queue<pair<int, int> > qu;
        for(int i = 0; i<n; i++){
            qu.push({i, (1<<i)});
            dp[i][(1<<i)] = 0;
        }
        
        while(!qu.empty()){
            auto [src, mask] = qu.front(); qu.pop();
            
            if(mask == full) return dp[src][mask];
            
            for(int nbr: adj[src]){
                int newBit = (mask|(1<<nbr));
                if(dp[nbr][newBit] != -1) continue;
                dp[nbr][newBit] = dp[src][mask] + 1;
                qu.push({nbr, newBit});
            }
        }
        
        return -1;
    }
};