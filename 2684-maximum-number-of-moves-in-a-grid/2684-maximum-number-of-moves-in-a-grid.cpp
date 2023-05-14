int n, m; 
const int N = 1001;
int dp[N][N];
class Solution {
    int rec(int i, int j, vector<vector<int> > &grid){
        if(j == m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int &ans = dp[i][j] = 0;
        if(i-1>=0 and j+1<m and grid[i-1][j+1] > grid[i][j]) ans = max(ans, 1 + rec(i-1, j+1, grid));
        if(i+1<n and j+1<m and grid[i+1][j+1] > grid[i][j]) ans = max(ans, 1 + rec(i+1, j+1, grid));
        if(j+1<m and grid[i][j+1] > grid[i][j]) ans = max(ans, 1 + rec(i, j+1, grid));
        
        return dp[i][j];
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof dp);
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans = max(ans, rec(i, 0, grid));
        }
        return ans;
    }
};