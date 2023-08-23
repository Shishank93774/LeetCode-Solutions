int cdp[11][2], pows[11];

int contri(int i, bool tight, const string &str, int n){
    if(i == n) return 1;
    if(tight == false) return pow(10, (n-i));
    
    int &cnt = cdp[i][tight];
    if(cnt != -1) return cnt;
    cnt = 0;
    int ub = (str[i] - '0');
    for(int dig = 0; dig<=ub; dig++){
        cnt += contri(i+1, (dig == ub), str, n);
    }
    
    return cnt;
}

int dp[11][2];
int rec(int i, bool tight, const string &str, int n){
    if(i == n) return 0;
    
    int &ans = dp[i][tight];
    
    if(ans != -1) return ans;
    ans = 0;
    
    int ub = (tight?(str[i] - '0'):9);
    
    for(int dig = 0; dig<=ub; dig++){
        if(dig == 1){
            ans += contri(i+1, (tight&(dig == ub)), str, n);
        }
        ans += rec(i+1, (tight&(dig == ub)), str, n);
    }
    return ans;
}

bool done = false;

class Solution {
public:
    int countDigitOne(int n) {
        if(!done){
            done = true;
            pows[0] = 1;
            for(int i = 1; i<10; i++) pows[i] = (pows[i-1]*10);
        }
        string str = to_string(n);
        memset(dp, -1, sizeof dp);        
        memset(cdp, -1, sizeof cdp);
        return rec(0, 1, str, str.size());
    }
};