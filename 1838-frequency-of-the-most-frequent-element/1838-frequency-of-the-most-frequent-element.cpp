#define ll long long
class Solution {
public:
    int maxFrequency(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<ll> pre(n);
        pre[0] = arr[0];
        for(int i = 1; i<n; i++) pre[i] = pre[i-1] + arr[i];
        int ans = 1;
        
        auto bs = [&](int x, int r)->int{
            int l = 0;
            int R = r;
            while(l<=r){
                int mid = l + (r - l)/2;
                
                ll rngSum = pre[R] - pre[mid] + arr[mid];
                ll reqSum = 1ll*(R-mid+1)*x;
                
                if(rngSum + k >= reqSum) r = mid - 1;
                else l = mid + 1;
            }
            return r+1;
        };
        
        for(int i = n-1; i>=0; i--){
            int cur = arr[i];
            int query = bs(cur, i);
            ans = max(ans, i-query+1);
        }
        return ans;
    }
};