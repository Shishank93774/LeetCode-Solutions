class Solution {
public:
    int maximumEnergy(vector<int>& arr, int k) {
        int ans = -1e9;
        int n = arr.size();
        vector<int> dp(n+1, -1e9);
        for(int i = 0; i<k; i++){
            dp[i] = arr[i];
            if(i+k>=n){
                ans = max(ans, dp[i]);
            }
        }
        for(int i = k; i<n; i++){
            dp[i] = max(dp[i-k] + arr[i], arr[i]);
            if(i+k>=n){
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};