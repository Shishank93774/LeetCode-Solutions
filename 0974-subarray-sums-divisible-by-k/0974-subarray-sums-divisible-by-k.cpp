class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        for(int i = 0; i<nums.size(); i++){
            nums[i] = abs(k + nums[i]%k);  // neg to pos
        }
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, ans = 0;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            sum %= k;
            ans += mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};