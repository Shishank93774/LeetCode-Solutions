class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int cnt[26] = {0}, n = words.size();
        for(string &word: words)
            for(char &c: word) cnt[c-'a']++;
        for(int i = 0; i<26; i++) if(cnt[i]%n) return false;
        return true;
    }
};