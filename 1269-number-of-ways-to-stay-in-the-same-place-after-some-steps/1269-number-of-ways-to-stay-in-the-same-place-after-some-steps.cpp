const int mod = 1e9+7;
class Solution {
public:
    int numWays(int steps, int lim) {
        
        vector<vector<int> > dp(steps, vector<int>(steps+1, -1));
        
        auto rec = [&](int pos, int rem, auto &&rec)->int{
            if(rem == 0) return (pos == 0);
            
            if(dp[pos][rem] != -1) return dp[pos][rem];
            int ans = 0;
            if(pos-1 >=0) ans += rec(pos-1, rem-1, rec);
            ans %= mod;
            ans += rec(pos, rem-1, rec);
            ans %= mod;
            if(pos+1<lim) ans += rec(pos+1, rem-1, rec);
            ans %= mod;
            
            return dp[pos][rem] = ans;
        };
        
        return rec(0, steps, rec);
        
    }
};