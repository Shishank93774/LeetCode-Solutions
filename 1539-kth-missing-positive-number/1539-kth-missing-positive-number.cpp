class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size() - 1, ans = 1;
        while(l<=r){
            int mid = l + (r - l)/2;
            int d = arr[mid] - (mid + 1);
            if(d < k){
                l = mid + 1;
                ans = arr[mid] + (k - d);
            }else if(d >= k){
                r = mid - 1;
                ans = arr[mid] + (k - d - 1);
            }
        }
        return ans;
    }
};