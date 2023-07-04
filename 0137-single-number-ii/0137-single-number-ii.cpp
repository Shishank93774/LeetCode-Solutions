class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // map<int, int> mp;
        // for(int x: nums)mp[x]++;
        // for(auto it: mp) if(it.second == 1) return it.first;
        // return -1;
        
        sort(nums.begin(), nums.end());
        int i = 1;
        while(i<nums.size()){
            if(nums[i-1] != nums[i]) return nums[i-1];
            i += 3;
        }
        return nums.back();
    }
};