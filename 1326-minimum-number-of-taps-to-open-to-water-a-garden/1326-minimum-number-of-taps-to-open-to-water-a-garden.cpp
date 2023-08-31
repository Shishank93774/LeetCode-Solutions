class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n+1, 1e9);
        vector<vector<int> > arr(n+1, vector<int>(2));
        dp[0] = 0;
        for(int i = 0; i<=n; i++){
            arr[i][0] = max(0, i-ranges[i]);
            arr[i][1] = min(n, i+ranges[i]);
        }
        
        for(int i = 0; i<=n; i++){
            for(int j = arr[i][0]; j<= arr[i][1]; j++){
                dp[arr[i][1]] = min(dp[arr[i][1]], dp[j]+1);
            }
        }
        
        return (dp[n]==1e9?-1:dp[n]);
    }
};