int avail;
int dp[11][2][2];
int rec(int i, bool tight, bool s, const string &str, int n){
    if(i == n) return s;
    
    int &ans = dp[i][tight][s];
    if(ans != -1) return ans;
    
    ans = 0;
    
    int ub = (tight?(str[i] - '0'):9);
    
    for(int dig = 0; dig<=ub; dig++){
        if(!s and dig == 0){
            ans += rec(i+1, (tight&(dig == ub)), 0, str, n);
        }
        if(avail&(1<<dig)){
            ans += rec(i+1, (tight&(dig == ub)), 1, str, n);
        }
    }
    return ans;
}

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        avail = 0;
        for(string s: digits){
            char ch = s[0];
            int b = ch-'0';
            avail = (avail|(1<<b));
        }
        
        string str = to_string(n);
        memset(dp, -1, sizeof dp);
        return rec(0, 1, 0, str, str.size());
    }
};