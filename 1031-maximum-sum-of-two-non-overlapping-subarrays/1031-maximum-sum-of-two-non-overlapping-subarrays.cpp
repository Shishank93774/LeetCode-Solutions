class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& arr, int x, int y) {
        int n = arr.size();
        int ans = 0;
        {            
            int dpR[n], dpL[n];
            memset(dpR, 0, sizeof dpR);
            memset(dpL, 0, sizeof dpL);
    
            int sum = 0;
            for(int i = 0; i<x; i++) sum += arr[i];
            dpR[x-1] = sum;
            for(int i = x; i<n; i++){
                sum += arr[i];
                sum -= arr[i-x];
                dpR[i] = max(dpR[i-1], sum);
            }
            
            sum = 0;
            for(int i = n-1; i>=n-y; i--) sum += arr[i];
            dpL[n-y] = sum;
            for(int i = n-1-y; i>=0; i--){
                sum += arr[i];
                sum -= arr[i+y];
                dpL[i] = max(dpL[i+1], sum);
            }
            for(int i = 1; i<n; i++){
                ans = max(ans, dpR[i-1] + dpL[i]);
            }
        }
        swap(x, y);
        {
            int dpR[n], dpL[n];
            memset(dpR, 0, sizeof dpR);
            memset(dpL, 0, sizeof dpL);
    
            int sum = 0;
            for(int i = 0; i<x; i++) sum += arr[i];
            dpR[x-1] = sum;
            for(int i = x; i<n; i++){
                sum += arr[i];
                sum -= arr[i-x];
                dpR[i] = max(dpR[i-1], sum);
            }
            
            sum = 0;
            for(int i = n-1; i>=n-y; i--) sum += arr[i];
            dpL[n-y] = sum;
            for(int i = n-1-y; i>=0; i--){
                sum += arr[i];
                sum -= arr[i+y];
                dpL[i] = max(dpL[i+1], sum);
            }
            for(int i = 1; i<n; i++){
                ans = max(ans, dpR[i-1] + dpL[i]);
            }
        }
        return ans;
    }
};