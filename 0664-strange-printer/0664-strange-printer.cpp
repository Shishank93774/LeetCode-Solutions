class Solution {
public:
    int strangePrinter(string &str) {
        
        int n = str.size();
        vector<vector<int> > dp(n, vector<int>(n, -1));
        auto rec = [&](int l, int r, auto &&rec)->int{
            if(l > r) return 0;
            if(l == r) return 1;
            
            if(dp[l][r] != -1) return dp[l][r];
            
            int &ans = dp[l][r] = (r-l+1);
            for(int i = l; i<r; i++){
                ans = min(ans, rec(l, i, rec) + rec(i+1, r, rec));
            }
            if(str[l] == str[r]) ans--;
            return ans;
        };
        
        return rec(0, n-1, rec);
    }
};