class Solution {
    int n, m, ans;
    void dfs(int r, int c, vector<vector<int> > &grid){
        if(r<0 or c<0 or r>=n or c>=m or grid[r][c] != 1) return;
        grid[r][c] = 2;
        dfs(r+1, c, grid);
        dfs(r-1, c, grid);
        dfs(r, c+1, grid);
        dfs(r, c-1, grid);
    }
    
public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        ans = -1;
        
        for(int i = 0; i<n; i++){
            bool chk = false;
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1) {
                    dfs(i, j, grid);
                    chk = true; break;
                }
            }
            if(chk) break;
        }
        
        queue<array<int, 2> > qu;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1) {
                    qu.push({i, j});
                }
            }
        }
        
        while(!qu.empty()){
            int sz = qu.size();
            while(sz--){
                auto pr = qu.front(); qu.pop();
                int x = pr[0], y = pr[1];
                if(x<0 or y<0 or x>=n or y>=m or grid[x][y] == 3) continue;
                if(grid[x][y] == 2) return ans;
                grid[x][y] = 3;
                qu.push({x+1, y});
                qu.push({x-1, y});
                qu.push({x, y+1});
                qu.push({x, y-1});
            }
            ans++;
        }
        return -1;
    }
};