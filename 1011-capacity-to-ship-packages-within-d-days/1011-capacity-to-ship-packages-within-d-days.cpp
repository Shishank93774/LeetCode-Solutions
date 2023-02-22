class Solution {
public:
    int shipWithinDays(vector<int>& arr, int k) {
        int l = *max_element(arr.begin(), arr.end()), r = accumulate(arr.begin(), arr.end(), 0);
        while(l<=r){
            int mid = l + (r-l)/2;
            int sum = 0;
            int req = 1;
            for(int i = 0; i<arr.size(); i++){
                if(sum + arr[i] > mid){
                    sum = arr[i];
                    req++;
                }else{
                    sum += arr[i];
                }
            }
            if(req <= k) r = mid - 1;
            else l = mid + 1;
        }
        return r + 1;
    }
};