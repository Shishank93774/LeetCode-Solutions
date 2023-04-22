const int N = 501;
int dp[N][N];
class Solution {
    int rec(int l, int r, const string &str){
        if(l >= r) return 0;
        if(l+1 == r) return !(str[l] == str[r]);
        if(dp[l][r] != -1) return dp[l][r];
        int &ans = dp[l][r] = INT_MAX;
        ans = 1 + rec(l+1, r, str);
        ans = min(ans, 1 + rec(l, r-1, str));
        if(str[l] == str[r]){
            ans = min(ans, rec(l+1, r-1, str));
        }
        return ans;
    }
public:
    int minInsertions(string s) {
        memset(dp, -1, sizeof dp);
        return rec(0, s.size()-1, s);
    }
};