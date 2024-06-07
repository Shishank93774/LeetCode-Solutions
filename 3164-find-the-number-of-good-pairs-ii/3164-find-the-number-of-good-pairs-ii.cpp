class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        for(int &x: nums2) x *= k;
        long long ans = 0;
        map<int, long long> mp;
        for(int x: nums1){
            for(int i = 1; i*i<=x; i++){
                if(x%i == 0){
                    mp[i]++;
                    if(i*i != x) mp[x/i]++;
                }
            }
        }
        
        for(int x: nums2) ans += mp[x];
        return ans;
    }
};