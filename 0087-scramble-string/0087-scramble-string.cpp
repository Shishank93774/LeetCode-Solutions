unordered_map<string, bool> mp;
class Solution {
public:
    bool isScramble(string s1, string s2) {
        short cnt[26] = {0}, n = s1.length();
        for(short i = 0; i<n; i++) cnt[s1[i] - 'a']++, cnt[s2[i] - 'a']--;
        for(short i = 0; i<26; i++) if(cnt[i]) return false;
        
        string cat = s1 + "|" + s2;
        if(mp.find(cat) != mp.end()) return mp[cat];
        if(s1 == s2) return mp[cat] = true;
        for(short i = 1; i<n; i++){
            bool b1 = isScramble(s1.substr(0, i), s2.substr(n-i)) && isScramble(s1.substr(i), s2.substr(0, n-i));
            if(b1) return mp[cat] = true;
            bool b2 = isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i));
            if(b2) return mp[cat] = true;
        }
        return mp[cat] = false;
    }
};