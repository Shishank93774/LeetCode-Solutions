int dx[5] = {0, 0, 0, 1, -1}, dy[5] = {0, 1, -1, 0, 0};

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int> > dp(n, vector<int>(m, INT_MAX));
        deque<pair<int, int> > dqu;
        dqu.push_front({0, 0});
        dp[0][0] = 0;
        while(!dqu.empty()){
            pair<int, int> f = dqu.front(); dqu.pop_front();
            int x = f.first, y = f.second;
            for(int i = 1; i<=4; i++){
                int tx = x + dx[i], ty = y + dy[i];
                if(tx <0 or ty <0 or tx >=n or ty >= m) continue;
                if(grid[x][y] == i){
                    if(dp[tx][ty] > dp[x][y] + 0){
                        dqu.push_front({tx, ty});
                        dp[tx][ty] = dp[x][y] + 0;
                    }
                }else{
                    if(dp[tx][ty] > dp[x][y] + 1){
                        dqu.push_back({tx, ty});
                        dp[tx][ty] = dp[x][y] + 1;
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};