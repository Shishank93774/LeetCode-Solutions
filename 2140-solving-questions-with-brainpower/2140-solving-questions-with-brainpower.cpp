class Solution {
public:
    long long mostPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        long long dp[n][2];
        dp[n-1][0] = 0;
        dp[n-1][1] = arr[n-1][0];
        for(int i = n-2; i>=0; i--){
            int f = arr[i][1];
            dp[i][0] = max(dp[i+1][0], dp[i+1][1]);
            dp[i][1] = 1ll*arr[i][0] + ((i+f+1)>=n?0:max(dp[i+f+1][0], dp[i+f+1][1]));
        }
        return max(dp[0][0], dp[0][1]);
    }
};