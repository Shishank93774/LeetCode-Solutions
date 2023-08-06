class Solution {
public:
    int minimumTotal(vector<vector<int>> &arr) {
        
        int n = arr.size();
        vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
        
        for(int r = n-1; r>=0; r--){
            for(int c = r; c>=0; c--){
                int ans = dp[r+1][c];
                ans = min(ans, dp[r+1][c+1]);
                ans += arr[r][c];
                dp[r][c] = ans;
            }
        }
        
        return dp[0][0];
    }
};