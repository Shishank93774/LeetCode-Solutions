const int mod = 1e9+7;
int dp[51][102][51];
class Solution {
    int rec(int i, int prv, int n, int m, int Krem){
        if(Krem < 0) return 0;
        if(i == n) return (Krem == 0);
        
        if(dp[i][prv+1][Krem] != -1) return dp[i][prv+1][Krem];
        
        int &ans = dp[i][prv+1][Krem] = 0;
        for(int cur = 1; cur<=m; cur++){
            if(cur > prv){
                ans += rec(i+1, cur, n, m, Krem-1);
            }else{
                ans += rec(i+1, prv, n, m, Krem);
            }
            ans %= mod;
        }
        
        return ans;
    }
public:
    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof dp);
        return rec(0, -1, n, m, k);
    }
};