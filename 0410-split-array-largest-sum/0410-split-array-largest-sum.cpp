class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long l = *max_element(nums.begin(), nums.end()), r = accumulate(nums.begin(), nums.end(), 0ll);
        int n = nums.size();
        long ans = INT_MAX;
        while(l<=r){
            long mid = l + (r - l)/2;
            int cnt = 1, i = 0;
            long sum = 0;
            while(i<n){
                if(sum + nums[i] > mid){
                    cnt++;
                    sum = nums[i];
                }else{
                    sum += nums[i];
                }
                i++;
            }
            if(cnt <= k){
                r = mid - 1;
                ans = min(ans, mid);
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};