class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> have(26, 0);
        for(char c: chars) have[c-'a']++;
        
        int ans = 0;
        for(int i = 0; i<words.size(); i++){
            vector<int> chave(have);
            bool chk = true;
            for(char c: words[i])
                if(chave[c-'a']-- == 0){
                    chk = false; break;
                }
            if(chk) ans += words[i].size();
        }
        return ans;
    }
};