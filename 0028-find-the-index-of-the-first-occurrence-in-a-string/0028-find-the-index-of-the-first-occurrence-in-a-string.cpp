int n, m, i, ti, j;
class Solution {
    int bruteForce(const string &t, const string &str){
        for(i = 0; i<n; i++){
            ti = i;
            j = 0;
            while(i<n and j<m and t[i++] == str[j++])
            if(j == m) return i-m;
            i = ti;
        }
        return -1;
    }
public:
    int strStr(string t, string str) {
        // return t.find(str);
        n = t.length(), m = str.length();
        return bruteForce(t, str);
    }
};