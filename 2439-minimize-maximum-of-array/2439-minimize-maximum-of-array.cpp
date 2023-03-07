class Solution {
public:
    int minimizeArrayValue(vector<int>& arr) {
        int l = arr[0], r = *max_element(arr.begin(), arr.end()), n = arr.size();
        int ans = arr[0];
        while(l<=r){
            int mid = l + (r - l)/2;
            int i = n-1;
            long ex = 0;
            while(i>=0){
                if(1ll*arr[i] + ex > mid){
                    ex = arr[i] + ex - mid;
                }else{
                    ex = 0;
                }
                i--;
            }
            if(ex > 0){
                l = mid + 1;
            }else{
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }
};