int dp[502][502];
class Solution {
public:
    int minDistance(const string &s, const string &p) {
        int n = s.length(), m = p.length();
        memset(dp, 0, sizeof(dp));
        for(int i = n+1; i>0; i--){
            for(int j = m+1; j>0; j--){
                if(i == n+1 and j == m+1) dp[i][j] = 0;
                else if(i == n+1) dp[i][j] = m-j+1;
                else if(j == m+1) dp[i][j] = n-i+1;
                else{
                    if(s[i-1] == p[j-1]) dp[i][j] = dp[i+1][j+1];
                    else dp[i][j] = min({dp[i+1][j+1], dp[i+1][j], dp[i][j+1]}) + 1;
                }
            }
        }
        return dp[1][1];
    }
};