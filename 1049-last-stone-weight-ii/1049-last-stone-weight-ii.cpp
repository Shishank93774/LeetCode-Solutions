class Solution {
public:
    int lastStoneWeightII(vector<int> &arr) {
        
        int n = arr.size();
        vector<vector<int> > dp(n, vector<int>(6001, -1));
        auto rec = [&](int i, int sum, auto &&rec)->int{
            if(i == n) return abs(sum);
            
            if(dp[i][sum+3000] != -1) return dp[i][sum+3000];
            
            int ans = rec(i+1, sum+arr[i], rec);
            ans = min(ans, rec(i+1, sum - arr[i], rec));
            
            return dp[i][sum+3000] = ans;
        };
        
        return rec(0, 0, rec);
    }
};