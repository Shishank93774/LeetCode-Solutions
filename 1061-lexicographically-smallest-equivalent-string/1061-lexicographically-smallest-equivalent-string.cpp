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
    if (i < j) swap(i, j);
    par[i] = j;
    sz[j] += sz[i];
    // if (rnk[i] == rnk[j]) rnk[j]++;
    return j;
  }
};

class Solution {
   public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU d(26);
        string ans = "";
        for(int i = 0; i<s1.length(); i++) d.merge(s1[i] - 'a', s2[i] - 'a');
        for(int i = 0; i<baseStr.length(); i++) ans += ('a' + d.find(baseStr[i] - 'a'));
        return ans;
    }
};