class Solution {
public:
    string reorganizeString(string &str) {
        map<char, int> mp;
        int n = str.size();
        for(char ch: str){
            mp[ch]++;
            if(mp[ch] > (n+1)/2) return "";
        }
        priority_queue<pair<int, char> > pqu;
        for(auto it: mp) pqu.push({it.second, it.first});
        string ans;
        while(pqu.size() > 1){
            auto p1 = pqu.top(); pqu.pop();
            auto p2 = pqu.top(); pqu.pop();
            ans += p1.second;
            ans += p2.second;
            p1.first--;
            p2.first--;
            if(p1.first) pqu.push(p1);
            if(p2.first) pqu.push(p2);
        }
        if(!pqu.empty()){
            if(pqu.top().first > 1) return "";
            ans += pqu.top().second;
        }
        return ans;
    }
};