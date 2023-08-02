class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<vector<int> > > dp(n+1, vector<vector<int> >(2+1, vector<int>(2, 0)));
        
        for(int i = n-1; i>=0; i--){
            for(int remk = 0; remk<=2; remk++){
                if(i == n) dp[i][remk][0] = dp[i][remk][1] = 0;
                else if(remk == 0) dp[i][remk][0] = dp[i][remk][1] = 0;
                else{
                    dp[i][remk][0] = dp[i+1][remk][0];
                    dp[i][remk][1] = dp[i+1][remk][1];
                    dp[i][remk][0] = max(dp[i][remk][0], - arr[i] + dp[i+1][remk][1]);
                    dp[i][remk][1] = max(dp[i][remk][1], arr[i] + dp[i+1][remk-1][0]);
                }
            }
        }
        
        return dp[0][2][0];
    }
};