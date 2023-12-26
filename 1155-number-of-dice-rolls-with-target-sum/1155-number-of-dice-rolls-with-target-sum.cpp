const int MOD = 1e9 + 7;
int dp[31][1001];
class Solution {
    int rec(int i, int n, int k, int sum, int x){
        if(sum > x) return 0;
        if(i == n) return (sum==x);
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        int ans = 0;
        for(int ex = 1; ex<=k; ex++) ans = (ans + (rec(i+1, n, k, sum+ex, x)))%MOD;

        return dp[i][sum] = ans;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return rec(0, n, k, 0, target);
    }
};