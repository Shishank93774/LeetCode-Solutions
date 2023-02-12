int n, i;
long long ans;
class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        n = roads.size();
        vector<int> adj[n+1];
        for(i = 0; i<n; i++) adj[roads[i][0]].push_back(roads[i][1]), adj[roads[i][1]].push_back(roads[i][0]);
        ans = 0;
        auto dfs = [&](int src, int par, auto &&dfs) -> int {
            int cnt = 1;
            for(int nbr: adj[src]) if(nbr != par) cnt += (int)dfs(nbr, src, dfs);
            if(src) ans += (cnt+seats-1)/seats;
            return cnt;
        };
        dfs(0, -1, dfs);
        return ans;
    }
};