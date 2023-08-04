class Solution {
public:
    int minSwap(vector<int> &arr, vector<int> &brr) {
        int n = arr.size(), m = brr.size();
        
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        auto rec = [&](int i, bool same, int prvA, int prvB, auto &&rec)->int{
            if(i == n) return 0;
            if(dp[i][same] != -1) return dp[i][same];
            
            int ans = 1e9;
            
            if(prvA < arr[i] and prvB < brr[i])
                ans = rec(i+1, true, arr[i], brr[i], rec);
            if(prvB < arr[i] and prvA < brr[i])
                ans = min(ans, 1 + rec(i+1, false, brr[i], arr[i], rec));
            
            return dp[i][same] = ans;
        };
        
        return rec(0, true, -1, -1, rec);
    }
};