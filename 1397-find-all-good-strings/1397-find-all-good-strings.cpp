const int mod = 1e9+7;

long long dp[501][2][2][51];
int lps[51];

class Solution {
    void getLPS(const string &pat){
        memset(lps, 0, sizeof lps);
        int j = 0;
        for(int i = 1; i<pat.size(); i++){
            while(j>0 and pat[i] != pat[j]) j = lps[j-1];
            
            if(pat[i] == pat[j]) lps[i] = ++j;
        }
    }
    int rec(int i, bool tl, bool th, int len, const string &s1, const string &s2, const string &evil, int n){
    if(len == evil.size()) return 0;
    if(i == n) return 1;
        
    long long &ans = dp[i][tl][th][len];
    if(ans != -1) return ans;
    ans = 0;
    
    char lb = (tl?s1[i]:'a');
    char ub = (th?s2[i]:'z');
    
    for(char ch = lb; ch <= ub; ch++){
        
        int nxtlen = len;
        while(nxtlen > 0 and evil[nxtlen] != ch)
            nxtlen = lps[nxtlen-1];
        if(ch == evil[nxtlen]) nxtlen++;
        
        ans += rec(i+1, (tl&(ch == lb)), (th&(ch == ub)), nxtlen, s1, s2, evil, n);
        ans %= mod;
    }
    return ans;
}
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        memset(dp, -1, sizeof dp);
        getLPS(evil);
        
        return rec(0, 1, 1, 0, s1, s2, evil, n);
    }
};