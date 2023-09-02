const int N = 51;
int dp[N];

class Solution {
    int rec(int i, const string &str, set<string> &st, int n){
        if(i >= n) return 0;
        
        if(dp[i] != -1) return dp[i];
        int &ans = dp[i] = rec(i+1, str, st, n) + 1;
        for(int len = 1; i+len<=n; len++){
            string sub = str.substr(i, len);
            if(st.find(sub) != st.end()){
                ans = min(ans, rec(i+len, str, st, n));
            }
        }
        return ans;
    }
public:
    int minExtraChar(string str, vector<string>& d) {
        memset(dp, -1, sizeof dp);
        set<string> st(d.begin(), d.end());
        int n = str.size();
        return rec(0, str, st, n);
    }
};