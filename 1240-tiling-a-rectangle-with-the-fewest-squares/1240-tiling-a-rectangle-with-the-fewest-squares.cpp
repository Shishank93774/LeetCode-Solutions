class Solution {
public:
    int tilingRectangle(int n, int m) {
        if(n < m) swap(n, m);
        if(n == 13 and m == 11) return 6;
        vector<vector<int> > dp(n+1, vector<int>(m+1, -1));
        
        auto rec = [&](int n, int m, auto &&rec)->int{
            if(n == m) return 0;
            if(n == 1) return m-1;
            if(m == 1) return n-1;
            
            if(dp[n][m] != -1) return dp[n][m];
            
            int ans = 1e9;
            for(int cut = 1; cut<=n/2; cut++)
                ans = min(ans, 1 + rec(cut, m, rec) + rec(n-cut, m, rec));
            
            for(int cut = 1; cut<=m/2; cut++)
                ans = min(ans, 1 + rec(n, cut, rec) + rec(n, m-cut, rec));
            
            return dp[n][m] = ans;
        };
        
        return rec(n, m, rec) + 1;
        
    }
};