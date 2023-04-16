const int N = 204+4;
int dp[N][N];
class Solution {
    bool rec(int i, int j, const string &a, const string &b, const string &c){
        if(i+j == c.size()) return true;
        if(i>a.size() or j>b.size()) return false;
        if(dp[i][j] != -1) return dp[i][j];
        int &ans = dp[i][j];
        ans = false;
        if(i<a.size() and j<b.size() and a[i] == c[i+j] and b[j] == c[i+j]){
            ans = rec(i+1, j, a, b, c) | rec(i, j+1, a, b, c);
        }else if(i<a.size() and a[i] == c[i+j]){
            ans = rec(i+1, j, a, b, c);
        }else if(j<b.size() and b[j] == c[i+j]){
            ans = rec(i, j+1, a, b, c);
        }else return false;
	    return ans;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        memset(dp, -1, sizeof dp);
	    return rec(0, 0, s1, s2, s3);
    }
};