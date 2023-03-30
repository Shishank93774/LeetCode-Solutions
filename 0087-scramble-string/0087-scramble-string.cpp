class Solution {
    unordered_map<string, bool> mp;
    bool rec(string s1, string s2, int n){
        if(mp.find(s1 + "|" + s2) != mp.end()) return mp[s1 + "|" + s2];
        if(s1 == s2) return mp[s1 + "|" + s2] = true;
        for(int i = 1; i<n; i++){
            bool b1 = rec(s1.substr(0, i), s2.substr(n-i), i) && rec(s1.substr(i), s2.substr(0, n-i), n-i);
            if(b1) return mp[s1 + "|" + s2] = true;
            bool b2 = rec(s1.substr(0, i), s2.substr(0, i), i) && rec(s1.substr(i), s2.substr(i), n-i);
            if(b2) return mp[s1 + "|" + s2] = true;
        }
        return mp[s1 + "|" + s2] = false;
    }
public:
    bool isScramble(string s1, string s2) {
        int cnt[26] = {0};
        for(char ch: s1) cnt[ch-'a']++;
        for(char ch: s2) cnt[ch-'a']--;
        for(int i = 0; i<26; i++) if(cnt[i]) return false;
        return rec(s1, s2, s1.size());
    }
};