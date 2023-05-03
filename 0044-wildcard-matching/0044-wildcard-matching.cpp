const int N = 2e3+3;
int dp[N][N];

class Solution{
    bool rec(int i, int j, const string &wild, const string &pat, int n, int m){
        if(i == n and j == m) return true;
        if(dp[i][j] != -1) return dp[i][j];
        int &ans = dp[i][j] = 0;
        if(wild[i] == pat[j]){
            ans = rec(i+1, j+1, wild, pat, n, m);
        }else{
            if(wild[i] == '?'){
                ans = rec(i+1, j+1, wild, pat, n, m);
            }else if(wild[i] == '*'){
                for(int k = j; k<=m; k++){
                    ans = (ans or rec(i+1, k, wild, pat, n, m));
                    if(ans) break;
                }
            }
        }
        return ans;
    }
public:
    bool isMatch(string pattern, string wild) {
        memset(dp, -1, sizeof dp);
        return rec(0, 0, wild, pattern, wild.size(), pattern.size());
    }
};