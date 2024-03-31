class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& arr) {
        long long ans = 0;
        int n = arr.size();
        int ex = 1;
        for(int i = 1; i<n; i++){
            if(arr[i-1] != arr[i]) ex++;
            else{
                ans += 1ll*ex*(ex+1)/2;
                ex = 1;
            }
        }
        ans += 1ll*ex*(ex+1)/2;
        return ans;
    }
};