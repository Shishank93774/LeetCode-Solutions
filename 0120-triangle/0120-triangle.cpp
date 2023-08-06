class Solution {
public:
    int minimumTotal(vector<vector<int>> &arr) {
        
        int n = arr.size();
        vector<vector<int> > dp(n, vector<int>(n, -1e9));
        
        auto rec = [&](int r, int c, auto &&rec)->int{
            if(r == n) return 0;
            
            if(dp[r][c] != -1e9) return dp[r][c];
            
            int ans = rec(r+1, c, rec);
            ans = min(ans, rec(r+1, c+1, rec));
            
            ans += arr[r][c];
            
            return dp[r][c] = ans;
        };
        
        return rec(0, 0, rec);
    }
};