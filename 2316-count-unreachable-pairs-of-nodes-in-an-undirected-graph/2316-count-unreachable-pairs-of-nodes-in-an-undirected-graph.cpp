struct DSU {
  vector<int> par, rnk, sz;  
  int c;
  DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n) {  // Constructor.
    for (int i = 1; i <= n; ++i) par[i] = i;
  }
  int find(int i) {
    return (par[i] == i ? i : (par[i] = find(par[i])));  // Path Compression along with find()
  }
  bool same(int i, int j) {
    return find(i) == find(j);  // is Connected?
  }
  int get_size(int i) {
    return sz[find(i)];
  }
  int count() {
    return c;    //connected components.
  }
  int merge(int i, int j) {  // Union funtion.
    if ((i = find(i)) == (j = find(j))) return -1;
    else --c;
    if (rnk[i] > rnk[j]) swap(i, j);
    par[i] = j;
    sz[j] += sz[i];
    if (rnk[i] == rnk[j]) rnk[j]++;
    return j;
  }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU d(n);
        set<int> pars;
        for(int i = 0; i<edges.size(); i++) d.merge(edges[i][0], edges[i][1]);
        for(int i = 0; i<n; i++) pars.insert(d.find(i));
        vector<long long> vec;
        long long tot = 0, ans = 0, cur = 0;
        for(int x: pars) vec.push_back(d.sz[x]), tot += d.sz[x];
        tot -= vec[0], cur = vec[0];
        for(int i = 1; i<vec.size(); i++) ans = ans + cur * tot, cur = vec[i], tot -= vec[i];
        return ans;
        
    }
};