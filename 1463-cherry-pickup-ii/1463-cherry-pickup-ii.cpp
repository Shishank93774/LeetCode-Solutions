int dp[71][71][71];
class Solution {
    int rec(int i, int j1, int j2, vector<vector<int>>& grid, int n, int m){
        if(i == n) return 0;
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int &ans = dp[i][j1][j2] = 0;
        for(int k1 = -1; k1 <= 1; k1++){
            for(int k2 = -1; k2 <= 1; k2++){
                int jj1 = j1 + k1, jj2 = j2 + k2;
                if(jj1 < 0 or jj1 >= m or jj2 < 0 or jj2 >= m) continue;
                int here = (j1 == j2? grid[i][j1]:grid[i][j1] + grid[i][j2]);
                ans = max(ans, here + rec(i+1, jj1, jj2, grid, n, m));
            }
        }
        return ans;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof dp);
        return rec(0, 0, grid[0].size()-1, grid, grid.size(), grid[0].size());
    }
};