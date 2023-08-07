class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        
        int n = arr.size();
        
        auto maxi = [&](int l, int r)->int{
            int mx = arr[l];
            while(l<=r){
                mx = max(mx, arr[l++]);
            }
            return mx;
        };
        vector<vector<int> >dp(n, vector<int>(n, -1));
        
        auto rec = [&](int l, int r, auto &&rec)->int{
            if(l >= r) return 0;
            if(l+1 == r) return arr[l]*arr[r];
            
            if(dp[l][r] != -1) return dp[l][r];
            
            int ans = 1e9;
            for(int k = l; k<r; k++){
                int cur = rec(l, k, rec) + rec(k+1, r, rec) + maxi(l, k)*maxi(k+1, r);
                ans = min(ans, cur);
            }
            
            return dp[l][r] = ans;
        };
        
        return rec(0, n-1, rec);
    }
};