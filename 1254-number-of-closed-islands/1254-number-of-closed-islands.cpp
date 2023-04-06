int dx[4] =  {0, 1, 0, -1};
int dy[4] =  {-1, 0, 1, 0};

class Solution {
    bool dfs(int x, int y, int m, int n, vector<vector<int>>& grid) {
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return false;
        }
        if (grid[x][y] == 1 || grid[x][y] == 2) {
            return true;
        }
        grid[x][y] = 2;
        bool isClosed = true;

        for (int i = 0; i < 4; i++) {
            int r = x + dx[i];
            int c = y + dy[i];
            if (!dfs(r, c, m, n, grid)) {
                isClosed = false;
            }
        }

        return isClosed;
    }
public:
    int closedIsland(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        int ans = 0;
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++)
                if(arr[i][j] == 0) ans += dfs(i, j, n, m, arr);
        return ans;
    }
};