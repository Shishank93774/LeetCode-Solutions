class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2, 0);
        long long xr = 0;
        for(int x: nums) xr ^= x;
        xr &= -xr;
        for(int x: nums){
            if(x&xr) ans[0] ^= x;
            else ans[1] ^= x;
        }
        return ans;
    }
};