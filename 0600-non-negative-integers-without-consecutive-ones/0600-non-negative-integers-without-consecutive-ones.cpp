int dp[32][2][3];
int rec(int i, bool tight, int prv, const string &str, int n){
    if(i == n) return 1;
    
    int &ans = dp[i][tight][prv+1];
    if(ans != -1) return ans;
    ans = 0;
    int ub = (tight?(str[i]-'0'):1);
    
    for(int dig = 0; dig<=ub; dig++){
        if(prv == 1 and dig == 1) continue;
        ans += rec(i+1, (tight&(dig==ub)), dig, str, n);
    }
    return ans;
    
}

class Solution {
public:
    int findIntegers(int n) {
        memset(dp, -1, sizeof dp);
        string rstr = bitset<32>(n).to_string();
        return rec(0, 1, 0, rstr, rstr.size());
    }
};