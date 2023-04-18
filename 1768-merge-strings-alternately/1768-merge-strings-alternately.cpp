class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int i = 0, j = 0, f = 0;
        while(i<word1.size() and j<word2.size())
            ans += f?word2[j++]:word1[i++], f = !f;
        while(i<word1.size())
            ans += word1[i++];
        while(j<word2.size())
            ans += word2[j++];
        return ans;
    }
};