int dxy[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

class Solution {
public:
    int latestDayToCross(int n, int m, vector<vector<int>>& cells) {
        int l = 0, r = cells.size();
        
        auto dfs = [&](int x, int y, vector<vector<int> > &grid, vector<vector<bool> > &vis, auto &&dfs) -> bool {
                vis[x][y] = true;
                if(x == n-1) return true;
                for(int i = 0; i<4; i++){
                    int tx = x + dxy[i][0], ty = y + dxy[i][1];
                    if(tx<0 or ty<0 or tx>=n or ty >=m or vis[tx][ty] or !grid[tx][ty]) continue;
                    if(dfs(tx, ty, grid, vis, dfs)) return true;
                }
                return false;
        };
        
        auto chk = [&](int x) -> bool{
            vector<vector<int> > grid(n, vector<int>(m, 1));
            vector<vector<bool> > vis(n, vector<bool>(m, false));
            for(int i = 0; i<x; i++) grid[cells[i][0]-1][cells[i][1]-1] = 0;
            for(int j = 0; j<m; j++) if(grid[0][j] and dfs(0, j, grid, vis, dfs)) return true;
            return false;
        };
        
        
        while(l<=r){
            int mid = l + (r - l)/2;
            if(chk(mid))
                l = mid + 1;
            else r = mid - 1;
        }
        
        return l - 1;
    }
};