const int mod = 1e9+7;
class Solution {
public:
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        
        vector<vector<vector<int> > > dp(n, vector<vector<int> >(m, vector<int>(maxMove+1, -1)));
        auto rec = [&](int r, int c, int rem, auto &&rec)->int{
            if(rem < 0) return 0;
            if(r<0 or c<0 or r>=n or c>=m) return 1;
            
            if(dp[r][c][rem] != -1) return dp[r][c][rem];
            int ans = 0;
            ans = (ans + rec(r+1, c, rem-1, rec))%mod;
            ans = (ans + rec(r-1, c, rem-1, rec))%mod;
            ans = (ans + rec(r, c+1, rem-1, rec))%mod;
            ans = (ans + rec(r, c-1, rem-1, rec))%mod;
            
            return dp[r][c][rem] = ans;
        };
        
        return rec(startRow, startColumn, maxMove, rec);
    }
};