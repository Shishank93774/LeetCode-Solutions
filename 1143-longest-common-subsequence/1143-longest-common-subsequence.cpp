auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();
class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int n = a.size(), m = b.size();
        int dp[n+1][m+1];
        for(int j = 0; j<=m; j++) dp[0][j] = 0;
        for(int i = 0; i<=n; i++) dp[i][0] = 0;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(a[i-1] == b[j-1]){
                    dp[i][j] = (1 + dp[i-1][j-1]);
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};