const int N = 1003;
int dp[N][N];

class Solution {
    int rec(string &str, int l, int r){
        if(dp[l][r] != -1) return dp[l][r];
        if(l > r) return 0;
        if(l == r) return 1;
        int &mx = dp[l][r];
        if(str[l] == str[r]){
            mx = max(mx, rec(str, l+1, r-1) + 2);
        }else{
            mx = max({mx, rec(str, l+1, r), rec(str, l, r-1)});
        }
        return mx;
    }
public:
    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof dp);
        return rec(s, 0, s.size()-1);
    }
};