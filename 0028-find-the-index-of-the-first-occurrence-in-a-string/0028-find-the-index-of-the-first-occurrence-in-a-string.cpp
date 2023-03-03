class Solution {
public:
    int strStr(string t, string str) {
        int n = t.length(), m = str.length();
        for(int i = 0; i<n; i++){
            int ti = i;
            int j = 0;
            while(i<n and j<m and t[i++] == str[j++])
            if(j == m) return i-m;
            i = ti;
        }
        return -1;
    }
};