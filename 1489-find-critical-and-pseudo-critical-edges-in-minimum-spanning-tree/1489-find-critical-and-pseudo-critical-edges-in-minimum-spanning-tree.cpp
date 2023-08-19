struct DSU{
    vector<int> par, rnk;
    int c;
    DSU(int n) : c(n){
        par.resize(n+1);
        rnk.assign(n+1, 0);
        for(int i = 0; i<=n; i++) par[i] = i;
    }
    
    int find(int i){
        return (i==par[i]?i:(par[i] = find(par[i])));
    }
    
    bool same(int i, int j){
        return find(i) == find(j);
    }
    
    int merge(int i, int j){
        if((i = find(i)) == (j = find(j))) return -1;
        --c;
        if(rnk[i] > rnk[j]) swap(i, j);
        par[i] = j;
        if(rnk[i] == rnk[j]) rnk[j]++;
        
        return j;
    }
};

class Solution {
    int getMST(vector<vector<int> > &edges, int n, int blockEdge, int forceEdge){
        DSU d(n);
        int wt = 0;
        
        if(forceEdge != -1){
            int u = edges[forceEdge][0], v = edges[forceEdge][1], w = edges[forceEdge][2];
            d.merge(u, v);
            
            wt += w;
        }
        
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];           
            if(i == blockEdge) continue;
            if(d.same(u, v)) continue;
            d.merge(u, v);
            wt += w;
        }
        if(d.c != 1) return 1e9;
        return wt;
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
        for(int i = 0; i<edges.size(); i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const vector<int> &v1, const vector<int> &v2){
            return v1[2] < v2[2];
        });
        vector<int> good, semiGood;
        
        int originalMSTWt = getMST(edges, n, -1, -1);
        
        for(int edge = 0; edge < edges.size(); edge++){
            if(originalMSTWt < getMST(edges, n, edge, -1))
                good.push_back(edges[edge][3]);
            else if(originalMSTWt == getMST(edges, n, -1, edge)) semiGood.push_back(edges[edge][3]);
        }
        
        return {good, semiGood};
        
    }
};