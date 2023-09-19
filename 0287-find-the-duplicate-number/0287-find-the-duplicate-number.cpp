class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int MAX = nums.size();
        for(int i = 0; i<nums.size(); i++){
            nums[nums[i]%MAX] += MAX;
        }
        int ans = 0;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] > 2*MAX) ans = i;
            nums[i] %= MAX;
        }
        return ans;
    }
};