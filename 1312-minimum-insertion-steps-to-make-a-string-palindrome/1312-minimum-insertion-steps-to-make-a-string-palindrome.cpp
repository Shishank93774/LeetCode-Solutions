class Solution {
public:
    int minInsertions(string &str) {
        
        int n = str.size();
        vector<vector<int> > dp(n, vector<int>(n, 1e9));
        
        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<n; j++){
                if(i>=j) dp[i][j] = 0;
                else if(i+1 == j) dp[i][j] = (str[i] != str[j]);
                else{
                    if(str[i] == str[j]) dp[i][j] = (i+1<n and j-1>=0)?dp[i+1][j-1]:1e9;
                    else dp[i][j] = 1 + min((i+1<n)?dp[i+1][j]:0, (j-1>=0)?dp[i][j-1]:0);
                }
            }
        }
        
        return dp[0][n-1];
    }
};