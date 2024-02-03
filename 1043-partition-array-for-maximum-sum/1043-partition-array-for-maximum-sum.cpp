const int N = 501;
int dp[N][N];

class Solution {
    int rec(int i, int len, int mx, vector<int> &arr, int n, int k){
        if(i == n) return mx*len;
        
        int &ans = dp[i][len];
        if(ans != -1) return ans;
        ans = rec(i+1, 1, arr[i], arr, n, k) + mx*len;
        
        if(len < k)
            ans = max(ans, rec(i+1, len+1, max(arr[i], mx), arr, n, k));
        
        return ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        for(int i = 0; i<=arr.size(); i++) for(int j = 0; j<=k; j++) dp[i][j] = -1;
        return rec(0, 0, 0, arr, arr.size(), k);
    }
};