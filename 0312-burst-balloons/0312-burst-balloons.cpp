const int N = 3e2+2;
int dp[N][N];
class Solution {
    int rec(int l, int r, vector<int> &arr){
        if(l > r) return 0;
        if(l == r) return arr[l]*arr[l-1]*arr[l+1];
        if(dp[l][r] != -1) return dp[l][r];
        
        int &ans = dp[l][r] = 0;
        for(int i = l; i<=r; i++){
            ans = max(ans, arr[l-1]*arr[i]*arr[r+1] + rec(l, i-1, arr) + rec(i+1, r, arr));
        }
        return ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        vector<int> arr;
        arr.push_back(1);
        for(int x: nums) arr.push_back(x);
        arr.push_back(1);
        
        return rec(1, nums.size(), arr);
    }
};