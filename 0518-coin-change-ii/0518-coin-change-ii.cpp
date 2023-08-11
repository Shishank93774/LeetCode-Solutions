int dp[300][5001];
class Solution {
public:
    int change(int x, vector<int> &arr) {
        memset(dp, -1, sizeof dp);
        int n = arr.size();
        auto rec = [&](int i, int rem, auto &&rec)->int{
            if(rem < 0) return 0;
            if(rem == 0) return 1;
            if(i == n) return 0;
            
            if(dp[i][rem] != -1) return dp[i][rem];
            int ans = rec(i+1, rem, rec);
            
            if(arr[i] <= rem) ans += rec(i, rem-arr[i], rec);
            
            return dp[i][rem] = ans;
        };
        
        return rec(0, x, rec);
        
    }
};