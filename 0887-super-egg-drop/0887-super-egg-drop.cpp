class Solution {
public:
    int superEggDrop(int n, int k) {
        int dp[n+1][k+1];
        memset(dp, -1, sizeof dp);
        auto rec = [&](int eggLeft, int floorsLeft, auto &&rec)->int{
            if(floorsLeft == 0) return dp[eggLeft][floorsLeft] = 0;
            if(floorsLeft == 1) return dp[eggLeft][floorsLeft] = 1;
            if(eggLeft == 0) return dp[eggLeft][floorsLeft] = 1e9;
            if(eggLeft == 1) return dp[eggLeft][floorsLeft] = floorsLeft;
            
            if(dp[eggLeft][floorsLeft] != -1) return dp[eggLeft][floorsLeft];
            
            int ans = 1e9;
            
            int l = 1, r = floorsLeft;
            int mn = 1e9;
            while(l<=r){
                int throws = l + (r - l)/2;
                int nb = rec(eggLeft, floorsLeft-throws, rec);
                int b = rec(eggLeft - 1, throws-1, rec);
                if(b < nb){
                    l = throws + 1;
                }else{
                    r = throws - 1;
                }
                mn = min(mn, max(nb, b));
            }
            ans = 1 + mn;
            return dp[eggLeft][floorsLeft] = ans;
        };
        
        return rec(n, k, rec);
    }
};