unordered_map<string, bool> dp;
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        int n = s1.size();

        vector<int> cnt(26, 0);
        
        for(int i = 0; i<n; i++) cnt[s1[i] - 'a']++, cnt[s2[i] - 'a']--;
        for(int i = 0; i<26; i++) if(cnt[i]) return false;
        
        string comb = s1 + s2;
        if(dp.find(comb) != dp.end()) return dp[comb];
        for(int i = 1; i<n; i++){
            if(isScramble(s1.substr(0, i), s2.substr(n-i)) and isScramble(s1.substr(i), s2.substr(0, n-i))) return dp[comb] = true;
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) and isScramble(s1.substr(i), s2.substr(i))) return dp[comb] = true;
        }
        return dp[comb] = false;
    }
};