class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int> > dp(n, vector<int>(n, 1e9));
        
        for(auto e: edges){
            int u = e[0], v = e[1], w = e[2];
            dp[u][v] = min(dp[u][v], w);
            dp[v][u] = min(dp[v][u], w); 
        }
        
        for(int i = 0; i<n; i++) dp[i][i] = 0;
        
        
        for(int k = 0; k<n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(dp[i][k] != 1e9 and dp[k][j] != 1e9 and dp[i][j] > dp[i][k] + dp[k][j]){
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }
                }
            }
        }
        
        int mn = 1e9, ans = -1;
        for(int i  = n-1; i>=0; i--){
            int cur = 0;
            for(int j = 0; j<n; j++){
                if(dp[i][j] <= distanceThreshold) cur++;
            }
            if(cur < mn){
                ans = i;
                mn = cur;
            }
        }
                
        return ans;
        
    }
};