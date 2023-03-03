int n, m;
const int MOD = 1e9 + 7, RADIX = 26, RADIX_1 = 26, RADIX_2 = 17, MOD_1 = 1000000033, MOD_2 = 2147483647;
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
    pair<long, long> hashPair(const string &str) {
        long hash1 = 0, hash2 = 0;
        long f1 = 1, f2 = 1;
        for (int i = m - 1; i >= 0; i--) {
            hash1 += ((int) (str[i] - 'a') * (f1)) % MOD_1, hash2 += ((int) (str[i] - 'a') * (f2)) % MOD_2;
            f1 = (f1 * RADIX_1) % MOD_1, f2 = (f2 * RADIX_2) % MOD_2;
        }
        return {hash1 % MOD_1, hash2 % MOD_2};
    }
    int rabinKarpDoubleHash(const string &t, const string &str){
        long MAX_WEIGHT_1 = 1, MAX_WEIGHT_2 = 1;
        for (int i = 0; i < m; i++) 
            MAX_WEIGHT_1 = (MAX_WEIGHT_1 * RADIX_1) % MOD_1, MAX_WEIGHT_2 = (MAX_WEIGHT_2 * RADIX_2) % MOD_2;
        
        pair<long, long> reqHash = hashPair(str);
        pair<long, long> haveHash = hashPair(t);
        if(reqHash == haveHash) return 0;
        for(int i = 1; i<=n-m; i++){
            haveHash.first = ((haveHash.first * RADIX_1) % MOD_1
                        - ((int) (t[i - 1] - 'a') * MAX_WEIGHT_1) % MOD_1
                        + (int) (t[i + m - 1] - 'a') + MOD_1) % MOD_1;
            haveHash.second = ((haveHash.second * RADIX_2) % MOD_2
                        - ((int) (t[i - 1] - 'a') * MAX_WEIGHT_2) % MOD_2
                        + (int) (t[i + m - 1] - 'a') + MOD_2) % MOD_2;
            if(reqHash == haveHash) return i;
        }
        return -1;
        
    }
    int zAlgo(const string &t, const string &str) {
        string s = str + "$" + t;
        int len = s.length();
        vector<int> z(len);
        for (int i = 1, l = 0, r = 0; i < len; ++i) {
            if (i <= r) z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < len && s[z[i]] == s[i + z[i]]) ++z[i];
            if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
        }
        for(int i = 0; i<len; i++) if(z[i] == m) return i - m - 1;
        return -1;
    }
    int kmpAlgo(const string &t, const string &str){
        vector<int> lps(m);
        int prv = 0, i = 1;
        while(i<m){
            if(str[i] == str[prv]){
                prv++;
                lps[i] = prv;
                i++;
            }else{
                if(prv == 0){
                    lps[i] = 0;
                    i++;
                }else{
                    prv = lps[prv-1];
                }
            }
        }
        int tPtr = 0, strPtr = 0;
        while(tPtr < n){
            if(t[tPtr] == str[strPtr]){
                tPtr++;
                strPtr++;
                if(strPtr == m) return tPtr - m;
            }else{
                if(strPtr == 0){
                    tPtr++;
                }else{
                    strPtr = lps[strPtr - 1];
                }
            }
        }
        return -1;
    }
public:
    int strStr(string t, string str) {
        // return t.find(str); 12ms
        n = t.length(), m = str.length();
        if(m > n) return -1;
        // return bruteForce(t, str); // 0ms
        // return rabinKarp(t, str); // 0ms
        // return rabinKarpDoubleHash(t, str); 4ms
        return zAlgo(t, str); // 0ms
        // return kmpAlgo(t, str);
        
    }
};