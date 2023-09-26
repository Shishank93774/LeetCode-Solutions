class Solution {
public:
    string removeDuplicateLetters(string s) {
        deque<char> qu;
        int cnt[26] = {};
        bool vis[26] = {};
        for(char &c: s) cnt[c-'a']++;
        for(char &c: s){
            if(vis[c-'a']) {cnt[c-'a']--; continue;}
            while(!qu.empty() and qu.back() > c){
                if(cnt[qu.back()-'a']){
                    vis[qu.back() - 'a'] = false;
                    qu.pop_back();
                }else break;
            }
            qu.push_back(c);
            vis[c-'a'] = true;
            cnt[c-'a']--;
        }
        string ans;
        while(!qu.empty()){
            ans += qu.front(); qu.pop_front();
        }
        return ans;
    }
};