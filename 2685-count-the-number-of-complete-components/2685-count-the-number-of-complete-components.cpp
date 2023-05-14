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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<bool> > g(n+1, vector<bool>(n+1, 0));
        DSU d(n);
        for(auto e: edges){
            d.merge(e[0], e[1]);
            g[e[0]][e[1]] = g[e[1]][e[0]] = true;
        }
        unordered_map<int, vector<int> > mp;
        for(int i = 0; i<n; i++){
            mp[d.find(i)].push_back(i);
        }
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<n; j++){
        //         cout<<g[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n";
        int ans = 0;
        for(auto it: mp){
            // cout<<it.first<<": ";
            auto v = it.second;
            // for(int i = 0; i<v.size(); i++) cout<<v[i]<<" ";
            // cout<<"\n";
            bool chk = true;
            for(int i = 0; i<v.size(); i++){
                for(int j = i+1; j<v.size(); j++){
                    if(!g[v[i]][v[j]] or !g[v[j]][v[i]]){
                        chk = false; break;
                    }
                }
            }
            ans += chk;
        }
        return ans;
    }
};