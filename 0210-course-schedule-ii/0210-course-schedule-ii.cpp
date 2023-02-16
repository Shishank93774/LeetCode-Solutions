class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& arr) {
        vector<int> ans;
        vector<int> adj[n];
        vector<int> inDeg(n, 0);
        vector<int> vis(n, false);
        vector<int> topo;
        for(int i = 0; i<arr.size(); i++){
            adj[arr[i][1]].push_back(arr[i][0]);
            inDeg[arr[i][0]]++;
        }
        auto topoSort = [&](int src, auto &&topoSort){
            if(vis[src]) return;
            vis[src] = true;
            topo.push_back(src);
            for(int nbr: adj[src]){
                if(vis[nbr]) continue;
                inDeg[nbr]--;
                if(inDeg[nbr] == 0) topoSort(nbr, topoSort); 
            }
        };
        for(int i = 0; i<n; i++) if(inDeg[i] == 0) topoSort(i, topoSort);
        if(topo.size() != n) topo.clear();
        return topo;
    }
};