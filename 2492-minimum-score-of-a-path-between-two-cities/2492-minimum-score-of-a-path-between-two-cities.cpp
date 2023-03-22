class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int, int> > adj[n+1];
        for(int i = 0; i<roads.size(); i++){
            int u = roads[i][0], v = roads[i][1], d = roads[i][2];
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }
        queue<int> qu;
        qu.push(1);
        vector<bool> vis(n+1, false);
        int ans = INT_MAX;
        while(!qu.empty()){
            int src = qu.front(); qu.pop();
            if(vis[src]) continue;
            vis[src] = true;
            for(auto it: adj[src]){
                ans = min(ans, it.second);
                qu.push(it.first);
            }
        }
        return ans;
    }
};