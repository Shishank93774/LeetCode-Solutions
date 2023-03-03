int n, m;
const int MOD = 1e9 + 7, RADIX = 26;
class Solution {
    int bruteForce(const string &t, const string &str){
        for(int i = 0; i<n; i++){
            int ti = i;
            int j = 0;
            while(i<n and j<m and t[i++] == str[j++])
            if(j == m) return i-m;
            i = ti;
        }
        return -1;
    }
    int hashValue(const string &str){
        int res = 0;
        long f = 1;
        for(int i = m-1; i>=0; i--) {
            res = (res + (1ll*(str[i] - 'a')*f)%MOD)%MOD;
            f = (f * RADIX)%MOD;
        }
        return (res%MOD);
    }
    int rabinKarp(const string &t, const string &str){
        long mxWt = 1, reqHash = hashValue(str), haveHash = hashValue(t);
        for(int i = 0; i<m; i++) mxWt = (mxWt * RADIX)%MOD;
        if(reqHash == haveHash) return 0;
        for(int i = 1; i<=n-m; i++){
            haveHash = ((haveHash * RADIX) % MOD - ((int) (t[i - 1] - 'a') * mxWt) % MOD
                        + (int) (t[i + m - 1] - 'a') + MOD) % MOD;
            if(reqHash == haveHash){
                int j = 0;
                while(j<m) if(t[i+j] != str[j++]) break;
                if(j == m) return i;
            }
        }
        return -1;
    }
public:
    int strStr(string t, string str) {
        // return t.find(str);
        n = t.length(), m = str.length();
        if(m > n) return -1;
        // return bruteForce(t, str); // 0ms
        return rabinKarp(t, str);
    }
};