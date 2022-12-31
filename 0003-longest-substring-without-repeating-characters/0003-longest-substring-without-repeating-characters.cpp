class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        unordered_map<char, int> mp;
        int ans = 0, cur = 0, lst = -1, n = str.length();
        for(int i = 0; i<n; i++){
            ans = max(ans, i - lst - 1);
            if(mp.find(str[i]) != mp.end() and mp[str[i]] >= lst) lst = mp[str[i]];
            mp[str[i]] = i;
        }
        ans = max(ans, n - lst - 1);
        return ans;
    }
};