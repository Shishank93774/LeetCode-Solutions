class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int> > dp(n, vector<int>(2, -1));
        auto rec = [&](int i, bool buy, auto &&rec)->int {
            if(i == n) return 0;

            if(dp[i][buy] != -1) return dp[i][buy]; 
            int &ans = dp[i][buy] = rec(i+1, buy, rec); // Do Nothing
            if(buy) // Can Buy?
                ans = max(ans, -prices[i] + rec(i+1, false, rec)); // Buy Now
            else
                ans = max(ans, prices[i] - fee + rec(i+1, true, rec)); // Sell Now
            return ans;
        };
        
        return rec(0, true, rec);
        
    }
};