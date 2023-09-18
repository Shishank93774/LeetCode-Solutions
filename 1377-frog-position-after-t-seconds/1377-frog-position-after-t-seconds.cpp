class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<int> adj[n+1];
        for(auto &e: edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<pair<int, double> > qu;
        qu.push({1, 1.0});
        
        vector<bool> vis(n+1, false);
        vis[1] = 1;
        
        while(t--){
            int sz = qu.size();
            while(sz--){
                auto pr = qu.front(); qu.pop();
                int u = pr.first;
                double prob = pr.second;
                                    
                int cnt = 0;
                for(int v: adj[u]){
                    if(vis[v]) continue;
                    cnt++;
                }
                
                if(cnt == 0){
                    qu.push(pr);
                }else{
                    for(int v: adj[u]){
                        if(vis[v]) continue;
                        vis[v] = 1;
                        qu.push({v, 1.0*prob/cnt});
                    }
                }
            }
        }
        
        while(!qu.empty()){
            auto pr = qu.front(); qu.pop();
            int u = pr.first;
            if(u == target) return pr.second;
        }
        
        return 0.0;
    }
};