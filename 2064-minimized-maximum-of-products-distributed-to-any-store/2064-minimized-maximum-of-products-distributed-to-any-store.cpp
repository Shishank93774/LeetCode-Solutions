class Solution {
public:
    int minimizedMaximum(int k, vector<int>& arr) {
        int n = arr.size(), ans = 0;
        int l = 0, r = 1e9;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(mid == 0){
                l = mid + 1;
                continue;
            }
            int i = 0, tot = 0;
            while(i<n){
                tot += (arr[i++] + mid - 1)/mid;
            }
            if(tot <= k){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};