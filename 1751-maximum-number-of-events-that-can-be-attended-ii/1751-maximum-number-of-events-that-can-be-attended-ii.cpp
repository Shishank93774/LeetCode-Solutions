class Solution {
public:
    int maxValue(vector<vector<int>>& arr, int tk) {
        
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        vector<vector<int> > dp(n, vector<int>(tk+1, -1));
        
        auto nxt = [&](int e, int l)->int{
            int r = n-1, ans = n;
            while(l<=r){
                int mid = l + (r - l)/2;
                
                if(arr[mid][0] > e) r = mid - 1, ans = mid;
                else l = mid + 1;
            }
            
            return ans;
        };
        
        auto rec = [&](int i, int k, auto &&rec) -> int{
            if(k == 0 or i == n) return 0;
            
            if(dp[i][k] != -1) return dp[i][k];
            
            int &ans = dp[i][k] = rec(i+1, k, rec);
            
            int j = nxt(arr[i][1], i+1);
            
            ans = max(ans, arr[i][2] + rec(j, k-1, rec));
            return ans;
        };
        
        return rec(0, tk, rec);
    }
};