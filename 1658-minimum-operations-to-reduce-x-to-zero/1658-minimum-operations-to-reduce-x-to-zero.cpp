class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int tar = accumulate(nums.begin(), nums.end(), 0);
        tar -= x;
        
        int n = nums.size(), i = 0, j = 0, sum = 0;
        int ans = -1;
        while(j<n){
            while(i<n and sum > tar)
                sum -= nums[i++];

            if(sum == tar) ans = max(ans, (j-i));
            sum += nums[j++];
        }
        while(i<n and sum > tar)
                sum -= nums[i++];
        if(sum == tar) ans = max(ans, (j-i));
        
        return (ans == -1?-1:(n - ans));
    }
};