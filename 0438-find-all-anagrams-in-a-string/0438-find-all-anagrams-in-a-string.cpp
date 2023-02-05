class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> req(26, 0);
        for(char ch: p) req[ch - 'a']++;
        vector<int> have(26, 0);
        int i = 0, j = 0, n = s.size(), m = p.size();
        while(i<n){
            while(j<n and j-i < m){
                have[s[j] - 'a']++;
                j++;
            }
            bool chk = true;
            for(int x = 0; x<26; x++) if(req[x] != have[x]) {
                chk = false; break;
            }
            if(chk) ans.push_back(i);
            have[s[i] - 'a']--;
            i++;
        }
        return ans;
    }
};