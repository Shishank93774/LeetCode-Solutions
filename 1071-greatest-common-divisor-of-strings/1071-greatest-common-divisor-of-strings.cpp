class Solution {
    bool isDivisor(string &str, string &t){
        int n = str.size(), m = t.size();
        if(n%m) return false;
        for(int i = 0; i<n/m; i++) for(int j = 0; j<m; j++) if(str[i*m+j] != t[j]) return false;
        return true;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        if(n<m){
            swap(n, m);
            swap(str1, str2);
        }
        string ans = "";
        for(int len = 1; len<=m; len++){
            string sub = str2.substr(0, len);
            if(isDivisor(str1, sub) and isDivisor(str2, sub)) ans = sub;
        }
        return ans;
    }
};