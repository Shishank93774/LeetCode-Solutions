bool vis[51][51];

class Solution {
    int dfs(int r, int c, vector<vector<int> > &grid, int n, int m){
        if(r<0 or c<0 or r>=n or c>=m or grid[r][c] == 0 or vis[r][c]) return 0;
        vis[r][c] = true;
        int ans = 1;
        ans += dfs(r+1, c, grid, n, m);
        ans += dfs(r-1, c, grid, n, m);
        ans += dfs(r, c+1, grid, n, m);
        ans += dfs(r, c-1, grid, n, m);
        
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        memset(vis, false, sizeof vis);
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++) if(!vis[i][j] and grid[i][j]) ans = max(ans, dfs(i, j, grid, n, m));
        
        return ans;
    }
};