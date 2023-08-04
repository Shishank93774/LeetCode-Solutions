class Solution {
public:
    bool canPartition(vector<int> &arr) {
        
        int n = arr.size();
        long long sum = accumulate(arr.begin(), arr.end(), 0ll);
        
        if(sum%2) return false;
        
        vector<vector<int> > dp(n, vector<int>(sum/2+1, -1));
        
        auto rec = [&](int i, int rem, auto &rec)->bool{
            if(rem == 0) return true;
            if(i == n) return false;
            
            if(dp[i][rem] != -1) return dp[i][rem];
            
            int ans = 0;
            ans = rec(i+1, rem, rec);
            if(ans) return dp[i][rem] = true;
            
            if(arr[i] <= rem) ans = rec(i+1, rem-arr[i], rec);
            
            return dp[i][rem] = ans;
        };
        
        return rec(0, sum/2, rec);
    }
};