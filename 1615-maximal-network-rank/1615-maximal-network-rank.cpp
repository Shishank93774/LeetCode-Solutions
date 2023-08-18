class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_set<int> > mp;
        vector<int> deg(n);
        for(auto r: roads){
            mp[r[0]].insert(r[1]);
            mp[r[1]].insert(r[0]);
            deg[r[0]]++;
            deg[r[1]]++;
        }
        int ans = 0;
        for(int u = 0; u<n; u++){
            for(int v = u+1; v<n; v++){
                int cur = deg[u] + deg[v];
                if(mp[u].count(v)) cur--;
                ans = max(ans, cur);
            }
        }
        
        return ans;
    }
};