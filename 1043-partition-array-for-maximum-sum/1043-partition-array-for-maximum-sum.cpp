int dp[501][501];
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        memset(dp, -1, sizeof dp);
        auto rec = [&](int i, int mx, int len, auto &&rec)->int{
            if(i == n) return (mx*len);
            
            int &ans = dp[i][len];
            if(ans != -1) return ans;
            ans = 0;
            
            if(len < k) {
                ans = rec(i+1, max(mx, arr[i]), len+1, rec);
            }
            ans = max(ans, mx*len + rec(i+1, arr[i], 1, rec));
            
            return ans;
        };
        
        return rec(0, 0, 0, rec);
        
    }
};