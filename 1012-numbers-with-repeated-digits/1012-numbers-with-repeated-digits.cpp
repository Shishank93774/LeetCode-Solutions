int dp[10][2][1024];
int rec(int i, bool tight, int bit, bool s, const string &str, int n){
    if(i == n) return s;
    
    int &ans = dp[i][tight][bit];
    if(ans != -1) return ans;
    
    ans = 0;
    int ub = (tight?(str[i] - '0'):9);
    
    for(int dig = 0; dig <=ub; dig++){
        if(!s and dig == 0){
            ans += rec(i+1, (tight&(dig == ub)), 0, bit, str, n);
        }else{
            if(bit&(1<<dig)) continue;
            ans += rec(i+1, (tight&(dig == ub)), bit|(1<<dig), 1, str, n);
        }

    }
    
    return ans;
}

class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string str = to_string(n);
        memset(dp, -1, sizeof dp);
        return n - rec(0, 1, 0, 0, str, str.size());
    }
};