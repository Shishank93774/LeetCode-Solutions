const int N = 1e5+5;
vector<bool> vis(N);
vector<int> adj[N];
string str;
vector<int> ans(N);

class Solution {
    vector<int> dfs(int src){
        if(vis[src]) return {};
        vis[src] = true;
        vector<int> cnts(26);
        cnts[str[src] - 'a']++;
        for(int nbr: adj[src]){
            if(vis[nbr]) continue;
            vector<int> v = dfs(nbr);
            for(int i = 0; i<26; i++) cnts[i] += v[i];
        }
        ans[src] = cnts[str[src] - 'a'];
        return cnts;
    }
public:
    vector<int> countSubTrees(int n, const vector<vector<int>>& edges, const string &labels) {
        for(int i = 0; i<n; i++) adj[i].clear();
        vis.assign(n, false);
        ans.assign(n, 0);
        str = labels;
        
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0);
        return ans;
        
    }
};