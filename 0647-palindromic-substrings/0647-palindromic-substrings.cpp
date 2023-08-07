class Solution {
public:
    int countSubstrings(string &str) {
        int n = str.size();
        vector<vector<int> > dp(n, vector<int>(n, -1));
        auto rec = [&](int l, int r, auto &&rec)->bool{
            if(l == r) return dp[l][r] = true;
            if(l+1 == r) return dp[l][r] = (str[l] == str[r]);
            
            if(dp[l][r] != -1) return dp[l][r];
            int ans = 0;
            if(str[l] == str[r]){
                return dp[l][r] = rec(l+1, r-1, rec);
            }
            return dp[l][r] = false;
        };
        int ans = 0;
        for(int l = 0; l<n; l++){
            for(int r = l; r<n; r++){
                if(rec(l, r, rec)) ans++;
            }
        }
        
        return ans;
    }
};