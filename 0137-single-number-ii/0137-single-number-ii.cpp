class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // map<int, int> mp;
        // for(int x: nums)mp[x]++;
        // for(auto it: mp) if(it.second == 1) return it.first;
        // return -1;
        
        // sort(nums.begin(), nums.end());
        // int i = 1;
        // while(i<nums.size()){
        //     if(nums[i-1] != nums[i]) return nums[i-1];
        //     i += 3;
        // }
        // return nums.back();
        
        // int n=nums.size();
        // unsigned int ans=0,shift=1;
        // for(int i=0;i<32;++i)
        // {
        //     int count=0;
        //     for(auto ele: nums)
        //     {
        //         if(ele & shift)
        //             count+=1;
        //     }
        //     if(count%3 != 0)
        //         ans += shift;
        //     shift*=2;
        // }
        // return ans;
        
        int ones = 0, twos = 0;
        for(int x: nums){
            ones = ((ones ^ x) & (~twos));
            twos = ((twos ^ x) & (~ones));
        }
        return ones;
    }
};