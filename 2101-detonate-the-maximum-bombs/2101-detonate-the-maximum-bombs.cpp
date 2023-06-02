class Solution {
    int bfs(int src, vector<int> adj[], int n){
        queue<int> qu;
        qu.push(src);
        int cnt = 0;
        vector<bool> vis(n, false);
        while(!qu.empty()){
            int f = qu.front(); qu.pop();
            if(vis[f]) continue;
            vis[f] = true;
            cnt++;
            for(int nbr: adj[f]){
                if(vis[nbr]) continue;
                qu.push(nbr);
            }
        }
        return cnt;
    }
public:
    int maximumDetonation(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> adj[n];
        for(int i = 0; i<n; i++){
            int x1 = arr[i][0], y1 = arr[i][1], r1 = arr[i][2];
            for(int j = 0; j<n; j++){
                if(i == j) continue;
                int x2 = arr[j][0], y2 = arr[j][1], r2 = arr[j][2];
                if(1ll*r1*r1 >= 1ll*(x2-x1)*(x2-x1) + 1ll*(y2-y1)*(y2-y1)) adj[i].push_back(j);
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++) ans = max(ans, bfs(i, adj, n));
        return ans;
    }
};