int dp[501][501][2];
bool vis[501][501][2];
class Solution {
    long long rec(int i, int j, bool taken, vector<int> &arr, vector<int> &brr, int n, int m){
        if(i == n or j == m) return taken?0:INT_MIN;
        
        if(vis[i][j][taken]) return dp[i][j][taken];
        
        long long ans = rec(i+1, j, taken, arr, brr, n, m);
        ans = max(ans, rec(i, j+1, taken, arr, brr, n, m));
        ans = max(ans, arr[i]*brr[j] + rec(i+1, j+1, true, arr, brr, n, m));
        vis[i][j][taken] = true;
        return dp[i][j][taken] = ans;
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof dp);
        memset(vis, false, sizeof vis);
        return rec(0, 0, false, nums1, nums2, nums1.size(), nums2.size());
    }
};