class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        vector<vector<int> > dp(n+1, vector<int>(n/2+1, -1));
        auto rec = [&](int done, int cap, auto &&rec)->int{
            if(done > n) return 1e9;
            if(done == n) return 0;
            if(n < done + cap) return 1e9;
            
            if(dp[done][cap] != -1) return dp[done][cap];
            
            int ans = 1e9;
            if(cap)
                ans = 1 + rec(done + cap, cap, rec); // paste now
            if(done != cap)
                ans = min(ans, 1 + rec(done, done, rec)); // copy all
            
            return dp[done][cap] = ans;
        };
        
        return rec(1, 0, rec);
    }
};