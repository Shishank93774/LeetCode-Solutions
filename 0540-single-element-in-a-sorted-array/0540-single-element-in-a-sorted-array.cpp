class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n - 1;
        while(l<=r){
            int mid = l + (r - l)/2;
            if(mid-1 >=0 and arr[mid] == arr[mid-1]){
                if(mid%2 == 0){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }else if(mid + 1< n and arr[mid] == arr[mid+1]){
                if(mid%2 == 0){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }else{
                return arr[mid];
            }
        }
        return -1;
    }
};