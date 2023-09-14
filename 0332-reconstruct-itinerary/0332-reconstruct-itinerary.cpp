class Solution {
    unordered_map<string, priority_queue<string, vector<string>, greater<string> > > mp;
    vector<string> ans;

    void dfs(string src){
        auto &edges = mp[src];
        while(!edges.empty()){
            string nbr = edges.top(); edges.pop();
            dfs(nbr);
        }
        ans.push_back(src);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        mp.clear();
        ans.clear();
        for(auto &t: tickets){
            mp[t[0]].push(t[1]);
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};