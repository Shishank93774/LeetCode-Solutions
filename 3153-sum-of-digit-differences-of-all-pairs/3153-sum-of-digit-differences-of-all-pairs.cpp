#define ll long long
class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<string> arr(n);
        for(int i = 0; i<n; i++){
            arr[i] = to_string(nums[i]);
        }
        
        ll ans = 0;
        int m = arr[0].size();
        for(int j = 0; j<m; j++){
            map<char, int> mp;
            for(int i = 0; i<n; i++){
                mp[arr[i][j]]++;
            }
            ll tot = n;
            for(auto [v, f]: mp){
                ans += f*(n-f);
            }
        }
        ans >>= 1;
        return ans;
    }
};