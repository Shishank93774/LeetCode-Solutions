class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int i = 0, n = nums.size();
        while(i<n){
            if(nums[i] == 0){
                int j = i + 1;
                while(j<n and nums[j] == 0) j++;
                int d = j - i;
                ans = ans + 1ll*d*(d+1)/2;
                i = j-1;
            }
            i++;
        }
        return ans;
    }
};