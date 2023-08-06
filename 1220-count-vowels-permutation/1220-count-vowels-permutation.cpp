vector<int> nxtPos[5] = {{1},{0,2},{0,1,3,4},{2,4},{0}};
const int mod = 1e9+7;
class Solution {
public:
    int countVowelPermutation(int n) {
        
        vector<vector<int> > dp(n, vector<int>(5, -1));
        auto rec = [&](int i, int prv, auto &&rec)->int{
            if(i == n) return 1;
            
            if(dp[i][prv] != -1) return dp[i][prv];
            int ans = 0;
            for(int nxt: nxtPos[prv]){
                ans += rec(i+1, nxt, rec);
                ans %= mod;
            }
            
            return dp[i][prv] = ans;
        };
        
        int ans = 0;
        for(int p = 0; p<5; p++){
            ans += rec(1, p, rec);
            ans %= mod;
        }
        return ans;
    }
};