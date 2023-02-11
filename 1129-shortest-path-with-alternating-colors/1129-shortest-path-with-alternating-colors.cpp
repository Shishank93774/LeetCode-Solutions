int u, v, i, src, nbr;
bool color, col;
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int, bool> > adj[n]; // red -> true
        
        for(i = 0; i<redEdges.size(); i++){ u = redEdges[i][0], v = redEdges[i][1];
            adj[u].push_back({v, true});
        }
        
        for(i = 0; i<blueEdges.size(); i++){ u = blueEdges[i][0], v = blueEdges[i][1];
            adj[u].push_back({v, false});
        }
        
        queue<pair<int, bool> > qu;
        vector<vector<int> > dists(n, vector<int>(2, -1));
        dists[0][0] = dists[0][1] = 0;
        
        for(auto pr: adj[0]) qu.push(pr);
        int d = 1;
        
        while(qu.size()){
            int sz = qu.size();
            while(sz--){
                auto pr = qu.front(); qu.pop();
                src = pr.first;
                color = pr.second;
                if(dists[src][color] != -1) continue;
                dists[src][color] = d;
                for(auto pr2: adj[src]){
                    nbr = pr2.first;
                    col = pr2.second;
                    if(dists[nbr][col] != -1 or color == col) continue;
                    qu.push({nbr, col});
                }
            }
            d++;
        }
        vector<int> ans(n);
        
        for(int i = 0; i<n; i++){
            ans[i] = min(dists[i][0]==-1?INT_MAX:dists[i][0], dists[i][1]==-1?INT_MAX:dists[i][1]);
            ans[i] = ans[i]==INT_MAX?-1:ans[i];
        }
        return ans;
    }
};