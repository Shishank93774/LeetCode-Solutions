class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int dpl[n], dpr[n];
        int mxp = 0;
        int mn = arr[0];
        for(int i = 1; i<n; i++){
            mn = min(mn, arr[i]);
            mxp = max(mxp, arr[i] - mn);
            dpl[i] = mxp;
        }
        mxp = 0;
        dpl[0] = dpr[n-1] = 0;
        int mx = arr[n-1];
        for(int i = n-2; i>=0; i--){
            mx = max(mx, arr[i]);
            mxp = max(mxp, mx - arr[i]);
            dpr[i] = mxp;
        }
        int ans = 0;
        for(int i = 0; i<n; i++) ans = max(ans, dpl[i] + dpr[i]);
        return ans;
    }
};