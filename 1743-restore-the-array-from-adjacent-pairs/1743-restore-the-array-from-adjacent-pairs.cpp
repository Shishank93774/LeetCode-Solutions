class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        unordered_map<int, vector<int> > adj;
        for(auto it: adjacentPairs){
            int a = it[0], b = it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> ans;
        unordered_set<int> vis;
        auto dfs = [&](int u, int t, auto &&dfs)->void{
            ans.push_back(u);
            vis.insert(u);
            for(int v: adj[u])
                if(vis.find(v) == vis.end()) dfs(v, t, dfs);
        };
        
        int s = 0;
        for(auto [v, f]: adj) if(f.size() == 1) s =  v;
        dfs(s, 0, dfs);
        
        return ans;
    }
};