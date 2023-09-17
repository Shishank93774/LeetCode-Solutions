class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        long long ans = *max_element(nums.begin(), nums.end());
        unordered_map<int, long long> mp;
        int x, v;
        for(int i = 0; i<nums.size(); i++){
            for(x = i+1, v = 2; v*v<=x; v++){
                while(x%(v*v) == 0){
                    x /= (v*v);
                }
            }
            mp[x] += nums[i];
            ans = max(ans, mp[x]);
        }
        
        return ans;
        
    }
};