class Solution {
public:
    int minEatingSpeed(vector<int>& arr, int h) {
        int n = arr.size();
        long l = 1, r = 1e10;
        long ans = n;
        while(l<=r){
            long mid = l + (r - l)/2;
            int i = 0;
            int timeReq = 0;
            while(i<n){
                timeReq += (arr[i++] + mid - 1)/mid;
            }
            if(timeReq <= h){
                r = mid - 1;
                ans = mid;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};