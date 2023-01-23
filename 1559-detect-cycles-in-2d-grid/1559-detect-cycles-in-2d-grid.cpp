int n, m;
bool chk;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(vector<vector<char> > &arr, vector<vector<bool> > &vis, int r, int c, int px, int py, int cnt){
    vis[r][c] = true;
    for(int i = 0; i<4; i++){
        int x = r + dx[i], y = c + dy[i];
        if(x<0 or y<0 or x>=n or y>=m or arr[x][y] != arr[r][c] or (x==px and y==py)) continue;
        if(vis[x][y]){
            if(cnt >= 4){
                chk = true; return;
            }
            continue;
        }
        dfs(arr, vis, x, y, r, c, cnt+1);
    }
}

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        chk = false;
        n = grid.size(), m = grid[0].size();
        vector<vector<bool > > vis(n+1, vector<bool>(m+1, false));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j] == 0){
                    dfs(grid, vis, i, j, -1, -1, 1);
                    if(chk) return true;
                }
            }
        }
        return false;
    }
};