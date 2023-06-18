const int mod = 1e9+7;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int> > dp(n, vector<int>(m, -1));
        int ans = 0;
        
        auto dfs = [&](int r, int c, auto &&dfs)->int{
            if(dp[r][c] != -1) return dp[r][c];
            int &ans = dp[r][c] = 1;
            for(int i = 0; i<4; i++){
                int tx = r + dx[i], ty = c + dy[i];
                if(tx<0 or ty<0 or tx>=n or ty>=m or grid[tx][ty] <= grid[r][c]) continue;
                ans = (1ll*ans + dfs(tx, ty, dfs))%mod;
            }
            return ans;
        };
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                ans = (1ll*ans + dfs(i, j, dfs))%mod;
            }
        }
        
        return ans;
    }
};