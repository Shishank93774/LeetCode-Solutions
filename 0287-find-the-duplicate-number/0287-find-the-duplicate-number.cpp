class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i<nums.size();){
            int x = nums[i];
            if(x == i+1){
                i++;
            }else if(x == nums[x-1]){
                return x;
            }else{
                nums[i] = nums[x-1];
                nums[x-1] = x;
            }
        }
        return -1;
    }
};