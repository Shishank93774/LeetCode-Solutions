#define ll long long
class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int mdpos = n/2;
        ll ans = 0;
        for(int i = 0; i<=mdpos; i++) ans += max(0, arr[i] - k);
        for(int i = mdpos; i<n; i++) ans += max(0, k - arr[i]);
        
        return ans;
    }
};