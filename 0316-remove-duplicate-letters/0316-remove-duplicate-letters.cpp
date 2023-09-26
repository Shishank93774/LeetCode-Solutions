class Solution {
public:
    string removeDuplicateLetters(string s) {
        int cnt[26] = {};
        bool vis[26] = {};
        for(char &c: s) cnt[c-'a']++;
        string ans;
        for(char &c: s){
            cnt[c-'a']--;
            if(vis[c-'a']) continue;
            while(!ans.empty() and ans.back() > c){
                if(cnt[ans.back()-'a']){
                    vis[ans.back()-'a'] = 0;
                    ans.pop_back();
                }else break;
            }
            ans += c;
            vis[c-'a'] = true;
        }
        return ans;
    }
};