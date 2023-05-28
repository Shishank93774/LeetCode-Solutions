const int N = 31, K = 31;
int dp[N][N][K];

class Solution {
    int rec(int l, int r, int piles, vector<int> &arr, vector<int> &pre, int k){
        if(l == r and piles == 1) return 0;
        
        if(dp[l][r][piles] != -1) return dp[l][r][piles];
        
        if(piles == 1){
            int ans = pre[r+1] - pre[l] + rec(l, r, k, arr, pre, k);
            return ans;
        }
        
        int &ans = dp[l][r][piles] = INT_MAX;
        for(int mid = l; mid<r; mid += (k-1)){
            ans = min(ans, rec(l, mid, 1, arr, pre, k) + rec(mid+1, r, piles-1, arr, pre, k));
        }
        
        return ans;
        
        
    }
public:
    int mergeStones(vector<int>& arr, int k) {
        int n = arr.size();
        if((n-1)%(k-1)) return -1;
        memset(dp, -1, sizeof dp);
        vector<int> pre(n+1);
        pre[0] = 0;
        for(int i = 0; i<n; i++) pre[i+1] = pre[i] + arr[i];
        return rec(0, arr.size()-1, 1, arr, pre, k);
    }
};