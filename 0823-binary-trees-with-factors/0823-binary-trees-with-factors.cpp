const int mod = 1e9+7;
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> dp;
        int ans = 0;
        for(int i = 0; i<n; i++){
            dp[arr[i]] = 1;
            for(int j = 0; j<i; j++){
                if(arr[i]%arr[j] == 0){
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]]*dp[arr[i]/arr[j]])%mod;
                }
            }
            ans += dp[arr[i]];
            ans %= mod;
        }
        return ans;
    }
};