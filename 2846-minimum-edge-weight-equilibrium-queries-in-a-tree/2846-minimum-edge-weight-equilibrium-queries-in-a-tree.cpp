struct LCATree{
    vector<vector<int> > st;
    int lg;
    vector<int> depth;

    int dfs(int i){
        if(depth[i] != -1) return depth[i];

        return depth[i] = dfs(st[i][0]) + 1;
    }

    LCATree(vector<int> &par):
     st(par.size(), vector<int>(__lg(par.size()) + 1)), lg(__lg(par.size()) + 1), depth(par.size(), -1){
        
        int n = par.size();
        par[0] = 0;
        depth[0] = 0;
        
        for(int i = 0; i<n; i++) st[i][0] = par[i];
        for(int i = 0; i<n; i++) dfs(i);

        for(int j = 1; j<lg; j++){
            for(int i = 0; i<n; i++){
                st[i][j] = st[ st[i][j-1] ][j-1];
            }
        }
    }

    int get_KthPar(int n, int k){
        if(depth[n] < k) return -1;
        for(int i = 0; i<lg; i++){
            if(k&(1<<i)) n = st[n][i];
        }

        return n;
    }

    int get_LCA(int a, int b){
        if(depth[a] < depth[b]) swap(a, b);

        int k = depth[a] - depth[b];

        for(int i = 0; i<lg; i++){
            if(k&(1<<i)) a = st[a][i];
        }

        if(a == b) return a;

        for(int i = lg-1; i>=0; i--){
            if(st[a][i] != st[b][i]){
                a = st[a][i];
                b = st[b][i];
            }
        }

        return st[a][0];
    }
};


class Solution {
    vector<vector<int> > dp;
    void dfs(int src, int p, vector<int> &par, const vector<vector<pair<int, int> > > &adj){
        
        for(auto &[nbr, w]: adj[src]){
            if(nbr == p) continue;
            par[nbr] = src;
            dfs(nbr, src, par, adj);
        }
    }
    vector<int> dfs2(int src, int p, vector<int> &up, const vector<vector<pair<int, int> > > &adj){
        
        for(auto &[nbr, w]: adj[src]){
            if(nbr == p) continue;
            up[w-1]++;
            auto v = dfs2(nbr, src, up, adj);
            up[w-1]--;
        }
        
        return dp[src] = up;
        
    }
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        dp.clear();
        dp.resize(n);
        vector<vector<pair<int, int> > > adj(n);
        for(auto e: edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        vector<int> par(n, 0);
        dfs(0, -1, par, adj);
        vector<int> up(26, 0);
        dfs2(0, -1, up, adj);
        LCATree lt(par);
        
        vector<int> ans;
        for(auto q: queries){
            int a = q[0], b = q[1];
            int lca = lt.get_LCA(a, b);
            auto v1 = dp[a];
            auto v2 = dp[b];
            auto v = dp[lca];
            int tot = 0, mx = 0;
            for(int i = 0; i<26; i++){
                tot += (v1[i] + v2[i] - 2*v[i]);
                mx = max(mx, v1[i] + v2[i] - 2*v[i]);
            }
            ans.push_back(tot-mx);
        }
        return ans;
        
        
    }
};