class Solution {
public:
    bool canPartition(vector<int> &arr) {
        
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum%2) return false;
        
        vector<bool> down(sum/2+1, false), cur(sum/2+1, false);
        
        for(int i = n-1; i>=0; i--){
            for(int rem = sum/2; rem>=0; rem--){
                if(rem == 0) cur[rem] = true;
                else{
                    cur[rem] = down[rem];
                    if(arr[i] <= rem) cur[rem] = cur[rem] or down[rem-arr[i]];
                }
            }
            down = cur;
        }
        
        return down[sum/2];
    }
};