const int N = 5e4+4;
int dp[N];

class Solution {
    int rec(int i, const vector<int> &arr, int n){
        if(i == n) return 0;
        
        if(dp[i] != -1) return dp[i];
        int &ans = dp[i] = arr[i] - rec(i+1, arr, n);
        if(i+1 < n) ans = max(ans, arr[i] + arr[i+1] - rec(i+2, arr, n));
        if(i+2 < n) ans = max(ans, arr[i] + arr[i+1] + arr[i+2] - rec(i+3, arr, n));
        
        return ans;
    }
public:
    string stoneGameIII(vector<int>& arr) {
        memset(dp, -1, sizeof dp);
        int ans = rec(0, arr, arr.size());
        return ans == 0?"Tie":ans>0?"Alice":"Bob";
    }
};