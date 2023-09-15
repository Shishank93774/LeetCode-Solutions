struct DSU{
    vector<int> par, rnk;
    DSU(int n){
        par.resize(n+1);
        for(int i = 0; i<n; i++) par[i] = i;
        rnk.assign(n+1, 0);
    }
    int find(int i){
        return (i==par[i]?i:(par[i] = find(par[i])));
    }
    bool same(int i, int j){
        return (find(i) == find(j));
    }
    int merge(int i, int j){
        if((i=find(i)) == (j=find(j))) return -1;
        if(rnk[i] > rnk[j]) swap(i, j);
        par[i] = j;
        if(rnk[i] == rnk[j]) rnk[j]++;
        return j;
    }
};
class Solution {
    int dist(const vector<int> &v1, const vector<int> &v2){
        return (abs(v1[0] - v2[0]) + abs(v1[1] - v2[1]));
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pqu;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int w = dist(points[i], points[j]);
                pqu.push({w, i, j});
            }
        }
        DSU d(n);
        int ans = 0, c = 1;
        while(!pqu.empty() and c<n){
            auto f = pqu.top(); pqu.pop();
            int w = f[0], u = f[1], v = f[2];
            if(d.same(u, v)) continue;
            d.merge(u, v);
            c++;
            ans += w;
        }
        return ans;
    }
};