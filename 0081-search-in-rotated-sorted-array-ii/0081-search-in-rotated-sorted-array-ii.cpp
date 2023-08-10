class Solution {
public:
    bool search(const vector<int>& arr, int x) {
        
        int l = 0, r = arr.size() - 1;
        while(l<=r){
            int mid = l + (r - l)/2;
            if(arr[l] == x or arr[mid] == x or arr[r] == x) return true;
            if(arr[mid] < x and x < arr[r]){
                l = mid + 1;
            }else if(x < arr[mid] and arr[l] < x){
                r = mid - 1;
            }else{
                l++; r--;
            }
        }
        return false;
    }
};