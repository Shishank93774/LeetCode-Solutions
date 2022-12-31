class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        map<int, int> mp;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            int vl = arr[i];
            int req = target - vl;
            if(mp.find(req) != mp.end()){
                return {mp[req], i};
            }
            mp[vl] = i;
        }
        return {-1, -1};
     }
};