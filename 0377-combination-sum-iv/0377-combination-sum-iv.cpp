class Solution {
public:
    int combinationSum4(vector<int>& arr, int x) {
        
        int n = arr.size();
        
        vector<int> dp(x+1, -1);
        
        auto rec = [&](int rem, auto &&rec)->int{
            if(rem == 0) return 1;
            
            if(dp[rem] != -1) return dp[rem];
            int ans = 0;
            for(int i = 0; i<n; i++){
                if(arr[i] <= rem) ans += rec(rem-arr[i], rec);
            }
            
            return dp[rem] = ans;
        };
        
        return rec(x, rec);
    }
};