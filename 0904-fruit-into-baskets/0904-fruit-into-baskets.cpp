class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int ans = 0, i = 0, j = 0, n = arr.size();
        unordered_map<int, int> mp;
        while(j<n){
            while(j<n and (mp.size() < 2 or mp.size() <= 2 and mp.find(arr[j]) != mp.end())){ 
                mp[arr[j]]++;
                ans = max(ans, j-i+1);
                j++;
            }
            mp[arr[i]]--; 
            if(mp[arr[i]] == 0) mp.erase(arr[i]);
            i++;
        }
        return ans;
    }
};