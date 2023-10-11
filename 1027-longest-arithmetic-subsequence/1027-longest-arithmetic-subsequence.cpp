class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        int ans = 0, n = nums.size();
        unordered_map<int, int> dp[n];
        dp[0] = {};
        for(int i = 1; i<n; i++){
            int cur = nums[i];
            for(int j = 0; j<i; j++){
                int prv = nums[j];
                int diff = cur - prv;
                dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans + 1;
    }
};