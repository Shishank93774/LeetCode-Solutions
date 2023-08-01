class Solution {
public:
    int minInsertions(string &str) {
        
        int n = str.size();
        vector<vector<int> > dp(n, vector<int>(n, -1));
        auto rec = [&](int i, int j, auto &&rec)->int{
            if(i >= j) return 0;
            if(i+1 == j) return (str[i] != str[j]);
            
            if(dp[i][j] != -1) return dp[i][j];
            
            if(str[i] == str[j]) return dp[i][j] = rec(i+1, j-1, rec);
            
            int a1 = 1 + rec(i+1, j, rec);
            int a2 = 1 + rec(i, j-1, rec);
            
            return dp[i][j] = min(a1, a2);
        };
        return rec(0, n-1, rec);
    }
};