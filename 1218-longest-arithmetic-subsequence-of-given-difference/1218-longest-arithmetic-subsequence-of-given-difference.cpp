class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        vector<int> dp(arr.size());
        dp[0] = 1;
        map<int, int> mp;
        mp[arr[0]] = 0;
        for(int i = 1; i<arr.size(); i++){
            int x = arr[i];
            int lst = x - diff;
            dp[i] = 1;
            if(mp.find(lst) != mp.end()) dp[i] += dp[mp[lst]];
            mp[arr[i]] = i;
        }
        return *max_element(dp.begin(), dp.end());
    }
};