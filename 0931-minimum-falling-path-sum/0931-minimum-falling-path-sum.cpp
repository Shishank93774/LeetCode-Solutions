auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 'c';
}();
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        int dp[n+1][m];
        for(int j = 0; j<m; j++) dp[0][j] = 0;
        int ans = 1e9;
        for(int i = 1; i<=n; i++){
            for(int j = 0; j<m; j++){
                dp[i][j] = dp[i-1][j];
                if(j-1 >= 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                if(j+1 < m) dp[i][j] = min(dp[i][j], dp[i-1][j+1]);
                dp[i][j] += arr[i-1][j];
                if(i == n) ans = min(dp[i][j], ans);
            }
        }
        return ans;
    }
};