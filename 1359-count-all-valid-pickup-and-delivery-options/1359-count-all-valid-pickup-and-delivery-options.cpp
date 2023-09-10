int dp[501];
const int mod = 1e9+7;
bool done = false;
class Solution {
    int rec(int n){
        if(n == 0) return 1;
        if(dp[n] != -1) return dp[n];
        long ans = n*(2*n-1);
        ans %= mod;
        ans = ans*rec(n-1);
        ans %= mod;
        return dp[n] = ans;
    }
public:
    int countOrders(int n) {
        if(!done){
            memset(dp, -1, sizeof dp);
            done = true;
        }
        return rec(n);
    }
};