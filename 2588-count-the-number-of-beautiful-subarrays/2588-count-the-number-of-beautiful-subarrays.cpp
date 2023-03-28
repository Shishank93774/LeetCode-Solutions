class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, long long> mp;
        long long ans = 0;
        int xr = 0;
        mp[0] = 1;
        for(int i = 0; i<nums.size(); i++){
            xr ^= nums[i];
            ans += mp[xr];
            mp[xr]++;
        }
        return ans;
    }
};