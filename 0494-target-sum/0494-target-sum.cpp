class Solution {
public:
    int findTargetSumWays(vector<int> &arr, int x) {
        
        int n = arr.size();
        vector<vector<int> > dp(n, vector<int>(2001, -1));
        auto rec = [&](int i, int sum, auto &&rec)->int{
            if(i == n) return (sum == x);
            
            if(dp[i][sum+1000] != -1) return dp[i][sum+1000];
            int a1 = rec(i+1, sum + arr[i], rec);
            int a2 = rec(i+1, sum - arr[i], rec);
            
            return dp[i][sum+1000] = a1 + a2;
        };
        
        return rec(0, 0, rec);
    }
};