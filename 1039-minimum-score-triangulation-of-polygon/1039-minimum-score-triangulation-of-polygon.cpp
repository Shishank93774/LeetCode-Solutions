class Solution {
public:
    int minScoreTriangulation(vector<int>& arr) {
        
        int n = arr.size();
        vector<vector<int> > dp(n, vector<int>(n, -1));
        auto rec = [&](int l, int r, auto &&rec)->int{
            if(l+2 > r) return 1e9;
            if(l+2 == r) return arr[l]*arr[l+1]*arr[r];
            
            if(dp[l][r] != -1) return dp[l][r];
            
            int ans = 1e9;
            for(int k = l+1; k<r; k++){
                if(k == l+1){
                    ans = min(ans, arr[l]*arr[k]*arr[r] + rec(k, r, rec));
                }else if(k == r-1){
                    ans = min(ans, arr[l]*arr[k]*arr[r] + rec(l, k, rec));
                }else{
                    ans = min(ans, arr[l]*arr[k]*arr[r] + rec(l, k, rec) + rec(k, r, rec));
                }
            }
            return dp[l][r] = ans;
        };
        
        return rec(0, n-1, rec);
        
    }
};