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
    int makeConnected(int n, vector<vector<int>>& conn) {
        if(conn.size() < n-1) return -1;
        DSU d(n);
        int cnt = 0;
        for(int i = 0; i<conn.size(); i++){
            int a = conn[i][0], b = conn[i][1];
            if(d.merge(a, b) == -1) cnt++;
        }
        return min(d.c - 1, cnt);
    }
};