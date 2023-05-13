class Solution {
    const int mod = 1e9+7;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int dp[high+1];
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        int ans = 0;
        for(int i = 1; i<=high; i++){
            if(i-zero>=0) dp[i] = (dp[i] + dp[i-zero])%mod;
            if(i-one>=0) dp[i] =  (dp[i] + dp[i-one])%mod;
            if(i >= low) ans = (ans + dp[i])%mod;
        }
        return ans;
    }
};