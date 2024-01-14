class Solution {
public:
    bool closeStrings(const string &word1, const string &word2) {
        vector<int> cnt1(26, 0), cnt2(26, 0);
        vector<bool> vis1(26, 0), vis2(26, 0);
        
        for(const char &c: word1) cnt1[c-'a']++, vis1[c-'a'] = 1;
        for(const char &c: word2) cnt2[c-'a']++, vis2[c-'a'] = 1;
        
        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());
        
        return (cnt1 == cnt2 and vis1 == vis2);
    }
};