class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int> mp;
        for(int x: nums) mp[x]++;
        int ans = 0;
        for(auto &[k, v]: mp){
            if(v == 1) return -1;
            if(v%3 == 0) ans += v/3;
            else if(v%3 == 2) ans += v/3 + 1;
            else ans += (v-3)/3 + 2;
        }
        
        return ans;
    }
};