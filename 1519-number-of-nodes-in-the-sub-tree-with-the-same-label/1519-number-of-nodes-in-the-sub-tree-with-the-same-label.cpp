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
        
//         unordered_map<unordered_set<int> > adj;
//          for(int i = 0; i<edges.size(); i++){
//             int u = edges[i][0], v = edges[i][1];
//             adj[u].insert(v);
//             adj[v].insert(u);
//         }
        
//         vector<vector<int> > cnts(n, vector<int>(26, 0));
//         queue<int> qu;
//         for(int i = 1; i<n; i++) {
//             cnts[i][labels[i] - 'a'] = 1; 
//             if(adj[i].size() == 1) qu.push(i);
//         }
//         cnts[0][labels[0] - 'a'] = 1; 
//         while(!qu.empty()){
//             int f = qu.front(); qu.pop();
//             int par = *(adj[f].begin());
//             adj[par].erase(f);
//             for(int i = 0; i<26; i++) cnts[par][i] += cnts[f][i];
//             if(par != 0 and adj[par].size() == 1) qu.push(par);
//         }
//         vector<int> ans(n);
//         for(int i = 0; i<n; i++) ans[i] = cnts[i][labels[i] - 'a'];
        return ans;
        
    }
};