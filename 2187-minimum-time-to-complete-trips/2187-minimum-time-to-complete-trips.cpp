class Solution {
public:
    long long minimumTime(vector<int>& arr, int totalTrips) {
        long long ans = 0;
        sort(arr.begin(), arr.end());
        long long l = 0, r = 1e18;
        while(l<=r){
            long long mid = l + (r - l)/2;
            int i = 0;
            long long tot = 0;
            while(i<arr.size()){
                tot += mid/arr[i++];
                if(tot >= totalTrips) break;
            }
            if(tot >= totalTrips){
                r = mid - 1;
                ans = mid;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};