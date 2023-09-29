class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> mp;
        for(int x: time) mp[x%60]++;
        int ans = 0;
        
        for(int l = 1, r = 59; l<r; l++, r--)
            ans += mp[l]*mp[r];
        
        ans += 1ll*mp[0]*(mp[0] - 1)/2;
        ans += 1ll*mp[30]*(mp[30] - 1)/2;
        return ans;
    }
};