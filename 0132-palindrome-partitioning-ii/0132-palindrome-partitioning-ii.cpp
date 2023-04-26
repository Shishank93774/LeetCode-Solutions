const int N = 2e3+3;
int dp[N];
class Solution {
    bool is_pali(const string &str){
        int l = 0, r = str.size() - 1;
        while(l<r) if(str[l++] != str[r--]) return false;
        return true;
    }
    
    int rec(int i, const string &str, int n){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int &ans = dp[i] = rec(i+1, str, n) + 1;
        string cur;
        cur += str[i];
        for(int j = i+1; j<n; j++){
            cur += str[j];
            if(is_pali(cur)) ans = min(ans, rec(j+1, str, n) + 1);
        }
        return ans;
    }
public:
    int minCut(string str) {
        memset(dp, -1, sizeof dp);
        return rec(0, str, str.size()) - 1;
    }
};
