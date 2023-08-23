int k;
int dp[11][2][11][11][21][2];
int rec(int i, bool tight, int cnte, int cnto, int sum, bool s, const string &str, int n){
    if(i == n) return ((cnte == cnto) and (sum == 0));
    
    int &ans = dp[i][tight][cnte][cnto][sum][s];
    if(ans != -1) return ans;
    
    ans = 0;
    
    int ub = (tight?(str[i] - '0'):9);
    
    for(int dig = 0; dig<=ub; dig++){
        if(!s and dig == 0){
            ans += rec(i+1, (tight&(dig == ub)), cnte, cnto, sum, 0, str, n);
        }else{
            ans += rec(i+1, (tight&(dig == ub)), cnte+((dig%2) == 0), cnto+((dig%2) == 1), (sum*10 + dig)%k, 1, str, n);
        }
    }
    return ans;
}

class Solution {
public:
    int numberOfBeautifulIntegers(int l, int r, int kk) {
        k = kk;
        string rstr = to_string(r);
        
        int lans = 0, rans = 0;
        memset(dp, -1, sizeof dp);
        rans = rec(0, 1, 0, 0, 0, 0, rstr, rstr.size());
        // cout<<rstr;
        
        if(l){
            l--;
            string lstr = to_string(l);
            memset(dp, -1, sizeof dp);
            lans = rec(0, 1, 0, 0, 0, 0, lstr, lstr.size());
        }
        
        return (rans - lans);
    }
};