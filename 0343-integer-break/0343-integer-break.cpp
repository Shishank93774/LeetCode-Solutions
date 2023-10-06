int dp[60];
class Solution {
public:
    Solution(){
         memset(dp, -1, sizeof dp);
    }
    int rec(int n){
        if(n <= 3) return n;
        if(dp[n] != -1) return dp[n];
        long long ans = n;
        for(int l = 1; l<n; l++){
            ans = max(ans, 1ll*l*rec(n-l));
        }
        
        return dp[n] = ans;
    }
    int integerBreak(int n) {
        if(n <= 3) return n-1;
        return rec(n);
    }
};