class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        unordered_map<int, vector<int> > adj;
        unordered_map<int, int> deg;
        for(auto it: adjacentPairs){
            int a = it[0], b = it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            deg[a]++;
            deg[b]++;
        }
        
        unordered_map<int, int> timer;
        auto dfs = [&](int u, int t, auto &&dfs)->void{
            timer[u] = t++;
            for(int v: adj[u]){
                if(timer.find(v) != timer.end()) continue;
                dfs(v, t, dfs);
            }
        };
        
        int s = 0;
        for(auto [v, f]: deg){
            if(f == 1) s = v;
        }
        
        dfs(s, 0, dfs);
        vector<pair<int, int> > vec;
        for(auto [v, f]: deg){
            vec.push_back({timer[v], v});
        }
        sort(vec.begin(), vec.end());
        vector<int> ans;
        for(auto [time, v]: vec) ans.push_back(v);
        return ans;
    }
};