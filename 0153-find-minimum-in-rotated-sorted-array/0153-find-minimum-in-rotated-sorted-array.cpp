class Solution {
public:
    int findMin(vector<int> &arr) {
        
        int l = 0, r = arr.size() - 1;
        int ans = 5001;
        while(l<=r){
            int mid = l + (r - l)/2;
            if(arr[l] <= arr[mid]){
                ans = min(ans, arr[l]);
                l = mid + 1;
            }else{
                ans = min(ans, arr[mid]);
                r = mid - 1;
            }
        }
        return ans;
        
    }
};