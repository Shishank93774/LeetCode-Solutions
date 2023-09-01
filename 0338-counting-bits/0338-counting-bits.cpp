class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0) return {0};
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        int msb = 1;
        for(int i = 2; i<=n; i++){
            if(msb == (i>>1)) msb <<= 1;
            dp[i] = 1 + dp[i-msb];
        }
        return dp;
    }
};