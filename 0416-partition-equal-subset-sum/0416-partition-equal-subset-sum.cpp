class Solution {
public:
    bool canPartition(vector<int> &arr) {
        
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum%2) return false;
        
        vector<vector<bool> > dp(n+1, vector<bool>(sum/2+1, false));
        
        for(int i = n-1; i>=0; i--){
            for(int rem = sum/2; rem>=0; rem--){
                if(rem == 0) dp[i][rem] = true;
                else{
                    dp[i][rem] = dp[i+1][rem];
                    if(arr[i] <= rem) dp[i][rem] = dp[i][rem] or dp[i+1][rem-arr[i]];
                }
            }
        }
        
        return dp[0][sum/2];
    }
};