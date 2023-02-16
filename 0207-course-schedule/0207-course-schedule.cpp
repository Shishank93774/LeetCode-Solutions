class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& arr) {
        vector<int> adj[n];
        vector<int> inDeg(n, 0);
        vector<int> vis(n, false);
        for(int i = 0; i<arr.size(); i++){
            adj[arr[i][0]].push_back(arr[i][1]);
            inDeg[arr[i][1]]++;
        }
        vector<int> topo;
        auto topoSort = [&](int src, auto &&topoSort) -> void {
            if(vis[src]) return;
            vis[src] = true;
            topo.push_back(src);
            for(int nbr: adj[src]){
                if(vis[nbr]) return;
                inDeg[nbr]--;
                if(inDeg[nbr] == 0) topoSort(nbr, topoSort);
            }
        };
        for(int i = 0; i<n; i++) if(inDeg[i] == 0) topoSort(i, topoSort);
        return topo.size() == n;
    }
};