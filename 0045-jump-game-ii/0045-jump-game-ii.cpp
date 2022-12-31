class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i<=nums[0] and i<n; i++) dp[i] = 1;
        for(int i = 1; i<n; i++){
            for(int j = 1; j<=nums[i] and i+j<n; j++) dp[i+j] = min(dp[i+j], dp[i]+1);
        }
        return dp[n-1];
    }
};