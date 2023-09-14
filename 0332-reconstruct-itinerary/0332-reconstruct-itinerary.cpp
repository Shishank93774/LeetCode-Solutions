class Solution {
    void dfs(string src, map<string, set<string> > &mp, map<pair<string, string>, int> &freq, vector<string> &ans, int n){
        if(ans.size() == (n+1)) return;
        for(const string &nbr: mp[src]){
            if(freq[{src, nbr}] == 0) continue;
            freq[{src, nbr}]--;
            ans.push_back(nbr);
            dfs(nbr, mp, freq, ans, n);
            if(ans.size() == (n+1)) return;
            ans.pop_back();
            freq[{src, nbr}]++;
        }
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, set<string> > mp;
        map<pair<string, string>, int> freq;
        for(auto &t: tickets){
            mp[t[0]].insert(t[1]);
            freq[{t[0], t[1]}]++;
        }
        int n = tickets.size();
        vector<string> ans;
        ans.push_back("JFK");
        dfs("JFK", mp, freq, ans, n);
        return ans;
    }
};