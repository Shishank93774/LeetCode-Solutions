class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 or obstacleGrid[n-1][m-1] == 1) return 0;
        int dp[n+1][m+1];
        for(int i = 0; i<=n; i++) dp[i][0] = 0;
        for(int j = 0; j<=m; j++) dp[0][j] = 0;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(obstacleGrid[i-1][j-1] == 1) dp[i][j] = 0;
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                dp[1][1] = 1; 
            }
        }
        return dp[n][m];
    }
};