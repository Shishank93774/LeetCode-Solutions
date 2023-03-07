class Solution {
public:
    int maximumCandies(vector<int>& arr, long long k) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), greater<int>());
        long long l = 0, r = 1e9;
        long long ans = 0;
        while(l<=r){
            long long mid = l + (r - l)/2;
            if(mid == 0){ l = mid + 1; continue;}
            int i = 0;
            long long tot = 0;
            while(i<n){
                tot += arr[i++]/mid;
                if(tot >= k) break;
            }
            if(tot >= k){
                l = mid + 1;
                ans = mid;
            }else{
                r = mid - 1;
            }
        }
        return ans;
    }
};