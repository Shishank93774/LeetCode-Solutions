class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return;
        int i = n-2;
        while(i>=0 and nums[i] >= nums[i+1]) i--;
        if(i>=0){
            int j = n-1;
            while(nums[i] >= nums[j]) j--;
            swap(nums[i], nums[j]);
        }
        i++;
        reverse(nums.begin()+i, nums.end());
    }
};