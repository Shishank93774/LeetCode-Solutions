class Solution {
public:
    int numTrees(int n) {
        
        vector<vector<int> >dp(n+1, vector<int>(n+1, -1));
        auto rec = [&](int l, int r, auto &&rec)->int{
            if(l > r) return 1;
            
            if(dp[l][r] != -1) return dp[l][r];
            
            int ans = 0;
            for(int k = l; k<=r; k++){
                ans += rec(l, k-1, rec)*rec(k+1, r, rec);
            }
            
            return dp[l][r] = ans;
        };
        
        return rec(1, n, rec);
    }
};