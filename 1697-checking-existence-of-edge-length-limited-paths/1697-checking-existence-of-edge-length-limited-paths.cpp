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
    bool static comp(const vector<int> &v1, const vector<int> &v2) {
         return v1[2] < v2[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<vector<int> > queryWithIndx(queries.size());
        for(int i = 0; i<queries.size(); i++){
            queryWithIndx[i] = queries[i];
            queryWithIndx[i].push_back(i);
        }
        sort(edgeList.begin(), edgeList.end(), comp);
        sort(queryWithIndx.begin(), queryWithIndx.end(), comp);
        
        vector<bool> ans(queries.size());
        int src, dest, q, id;
        int curIdx = 0;
        DSU d(n);
        for(auto it : queryWithIndx){
            src = it[0], dest = it[1], q = it[2], id = it[3];
            while(curIdx < edgeList.size() and edgeList[curIdx][2] < q){
                d.merge(edgeList[curIdx][0], edgeList[curIdx][1]);
                curIdx++;
            }
            ans[id] = d.same(src, dest);
        }
        return ans;
    }
};