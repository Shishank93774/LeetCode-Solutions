vector<int> nxtPos[5] = {{1},{0,2},{0,1,3,4},{2,4},{0}};
const int mod = 1e9+7;
class Solution {
public:
    int countVowelPermutation(int n) {
        
        vector<vector<int> > dp(n+1, vector<int>(5, 0));
        
        for(int p = 0; p<5; p++) dp[n][p] = 1;
        for(int i = n-1; i>=0; i--){
            for(int p = 0; p<5; p++){
                int ans = 0;
                for(int nxt: nxtPos[p]){
                    ans += dp[i+1][nxt];
                    ans %= mod;
                }
                dp[i][p] = ans;
            }
        }
        int ans = 0;
        for(int p = 0; p<5; p++){
            ans += dp[1][p];
            ans %= mod;
        }
        return ans;
    }
};