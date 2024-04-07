struct DSU{
    vector<int> par, rnk, sz, cost;
    DSU(int n): par(n+1), sz(n+1, 1), rnk(n+1, 0), cost(n+1, INT_MAX) {
        for(int i = 0; i<=n; i++) par[i] = i;
    }
    
    int find(int i){
        return par[i] == i? i: (par[i] = find(par[i]));
    }
    
    int merge(int i, int j, int w){
        if((i = find(i)) == (j = find(j))){
            cost[i] &= w;
            return -1;
        }
        
        if(sz[i] < sz[j]) swap(i, j);
        sz[i] += sz[j];
        
        par[j] = i;
        cost[i] &= (cost[j] & w);
        
        return i;
    }  
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        DSU d(n);
        for(int i = 0; i<edges.size(); i++){
            d.merge(edges[i][0], edges[i][1], edges[i][2]);
        }
        
        vector<int> ans(queries.size());
        for(int i = 0; i<queries.size(); i++){
            int u = queries[i][0], v = queries[i][1];
            if(u == v) ans[i] = 0;
            else{
                int pu = d.find(u), pv = d.find(v);
                if(pu != pv) ans[i] = -1;
                else ans[i] = d.cost[pu];
            }
        }
        
        
        return ans;
    }
};