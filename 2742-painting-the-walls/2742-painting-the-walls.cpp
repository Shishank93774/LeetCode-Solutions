int dp[501][501];
class Solution {
    int rec(int i, int wallsLeft, vector<int> &cost, vector<int> &time, int n){
        if(wallsLeft <= 0) return 0;
        if(i == n) return 1e9;
        
        if(dp[i][wallsLeft] != -1) return dp[i][wallsLeft];
        
        int &ans = dp[i][wallsLeft] = rec(i+1, wallsLeft, cost, time, n);
        
        ans = min(ans, rec(i+1, wallsLeft-1-time[i], cost, time, n) + cost[i]);
        
        return ans;
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp, -1, sizeof dp);
        return rec(0, cost.size(), cost, time, cost.size());
    }
};