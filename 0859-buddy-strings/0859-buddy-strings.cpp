class Solution {
public:
    bool buddyStrings(string &str, string &t) {
        int n = str.size();
        if(n == 1 or n != (int)t.size()) return false;
        if(n == 2) return str[0] == t[1] and str[1] == t[0];
        if(str == t and n != (int)set<char>(str.begin(), str.end()).size()) return true;
        int cnt = 0, p1 = -1, p2 = -1;
        for(int i = 0; i<n; i++){
            if(str[i] != t[i]){
                cnt++;
                if(p1 == -1) p1 = i;
                else p2 = i;
            }
            if(cnt > 2) return false;
        }
        return (cnt == 2 and str[p1] == t[p2] and str[p2] == t[p1]);
    }
};