const int MOD = 1e9+7;
class Solution {
public:
    int waysToSplit(vector<int>& arr) {
        int ans = 0, n = arr.size();
        vector<int> pre(n);
        
        for(int i = 0; i<n; i++) (pre[i] = (i==0?0:pre[i-1]) + arr[i]);
        int tsum = pre[n-1];
        
        for(int i = 0, j = 0, k = 0; i+2<n; i++){
            j = max(i+1, j);
            while(j+1<n and (pre[j] < 2*pre[i])) ++j;
            k = max(j, k);
            while(k+1<n and (tsum + pre[i] >= 2*pre[k])) ++k;
            ans = (1ll*ans + (k - j))%MOD;
        }
        return ans;
    }
};