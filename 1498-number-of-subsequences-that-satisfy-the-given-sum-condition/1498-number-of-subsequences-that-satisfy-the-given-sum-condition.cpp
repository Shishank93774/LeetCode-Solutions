const int MOD = 1e9+7;
class Solution {
public:
    int numSubseq(vector<int>& arr, int target) {
        int ans = 0, n = arr.size();
        sort(arr.begin(), arr.end());
        int l = 0, r = n-1;
        int pwr[n+1];
        pwr[0] = 1;
        for(int i = 1; i<=n; i++){
            pwr[i] = (1ll*pwr[i-1]*2)%MOD;
        }
        while(l<=r){
            if(arr[l] + arr[r] <= target){
                ans = (1ll*ans + pwr[r-l])%MOD;
                l++;
            }else r--;
        }
        return ans;
    }
};