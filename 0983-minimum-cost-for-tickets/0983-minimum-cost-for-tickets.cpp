class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int mx = days[days.size()-1], j = 0;
        int dp[mx+1];
        dp[0] = 0;
        
        for(int i = 1; i<=mx; i++)
            if(days[j] == i) dp[i] = min({dp[max(i-1, 0)] + costs[0], dp[max(i-7, 0)] + costs[1], dp[max(i-30, 0)] + costs[2]}), j++;
            else dp[i] = dp[i-1];
        
        return dp[mx];
    }
};