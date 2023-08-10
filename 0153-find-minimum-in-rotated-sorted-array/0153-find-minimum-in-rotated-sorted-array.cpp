class Solution {
public:
    int findMin(vector<int> &arr) {
        
        int l = 0, r = arr.size() - 1;
        
        while(l<r){
            if(arr[l] < arr[r]) return arr[l];
            int mid = l + (r - l)/2;
            if(arr[l] <= arr[mid])
                l = mid + 1;
            else
                r = mid;
        }
        return arr[l];
        
    }
};