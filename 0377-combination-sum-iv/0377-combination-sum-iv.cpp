const long long mod = 1e18+7;
class Solution {
public:
    int combinationSum4(vector<int>& arr, int x) {
        
        int n = arr.size();     
        vector<long long> dp(x+1, -1);        
        dp[0] = 1;
        for(int rem = 1; rem <= x; rem++){
            long long ans = 0;
            for(int i = 0; i<n; i++)
                if(arr[i] <= rem) ans = (ans + dp[rem-arr[i]])%mod;
            
            dp[rem] = ans;
        }
        return dp[x];
    }
};