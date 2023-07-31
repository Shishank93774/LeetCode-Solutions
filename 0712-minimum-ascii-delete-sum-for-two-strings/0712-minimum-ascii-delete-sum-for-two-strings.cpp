class Solution {
public:
    int minimumDeleteSum(string &s1, string &s2) {
        
        int n = s1.size(), m = s2.size();
        vector<vector<int> > dp(n, vector<int>(m, -1));
        auto rec = [&](int i, int j, auto &&rec)->int{
            if(i == n){
                int todel = 0;
                for(int k = j; k<m; k++) todel += s2[k];
                return todel;
            }
            if(j == m){
                int todel = 0;
                for(int k = i; k<n; k++) todel += s1[k];
                return todel;
            }
            
            if(dp[i][j] != -1) return dp[i][j];
            
            int &ans = dp[i][j] = rec(i+1, j, rec) + s1[i];
            
            ans = min(ans, rec(i, j+1, rec) + s2[j]);
            
            if(s1[i] == s2[j]) ans = min(ans, rec(i+1, j+1, rec));
            
            return ans;
        };
        
        
        return rec(0, 0, rec);
    }
};