class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        vector<int> tmp(n, INT_MAX);
        k++;
        dist[src] = 0;
        while(k--){
            for(auto &it: flights){
                int u = it[0], v = it[1], w = it[2];
                if(dist[u] != INT_MAX){
                    if(tmp[v] > dist[u] + w)
                        tmp[v] = dist[u] + w;
                }
            }
            dist = tmp;
        }
        return ((dist[dst] == INT_MAX)?-1:dist[dst]);
    }
};