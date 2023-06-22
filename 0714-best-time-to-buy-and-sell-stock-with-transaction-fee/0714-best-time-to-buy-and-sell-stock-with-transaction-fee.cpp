int dp[50005][2]; // Buy at this day           OR        Sell at this day

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        memset(dp, 0, sizeof(dp));
        dp[1][0] = -prices[0];
        
        for(int i = 2; i<=n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - (prices[i-1]));
            dp[i][1] = max(dp[i-1][1], prices[i-1] + dp[i-1][0] - fee);
        }
        
        return dp[n][1];
    }
};