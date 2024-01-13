class Solution {
public:
    int minSteps(string s, string t) {
        int cnt[26];
        for(int i = 0; i<26; i++) cnt[i] = 0;
        for(char c: s) cnt[c-'a']++;
        for(char c: t) cnt[c-'a']--;
        int ans = 0;
        for(int i = 0; i<26; i++) ans += abs(cnt[i]);
        return (ans>>1);
    }
};