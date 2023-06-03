class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<array<int, 2> > adj[n];
        for(int i = 0; i<n; i++){
            int u = manager[i], v = i;
            if(u != -1) {
                int t = informTime[u];
                adj[u].push_back({v, t});
            }
        }
        vector<int> dist(n, INT_MAX);
        queue<array<int, 2> > qu;
        qu.push({headID, 0});
        while(!qu.empty()){
            auto f = qu.front(); qu.pop();
            int u = f[0], w = f[1];
            dist[u] = w;
            for(auto pr: adj[u]){
                int nbr = pr[0], wt = pr[1];
                if(dist[nbr] > w + wt){
                    qu.push({nbr, w + wt});
                }
            }
        }
        return *max_element(dist.begin(), dist.end());
    }
};