class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> req(26, 0);
        for(char ch: s1) req[ch-'a']++;
        int n = s1.size(), m = s2.size(), i = 0, j = 0;
        vector<int> tmp(26, 0);
        while(i<m){
            while(j<m and j-i < n){
                tmp[s2[j] - 'a']++;
                j++;
            }
            bool chk = true;
            for(int x = 0; x<26; x++) if(tmp[x] != req[x]){
                chk = false;
                break;
            }
            if(chk) return chk;
            tmp[s2[i] - 'a']--;
            i++;
        }
        return false;
    }
};