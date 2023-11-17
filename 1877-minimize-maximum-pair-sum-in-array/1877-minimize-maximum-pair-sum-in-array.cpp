class Solution {
public:
    int minPairSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = arr[0] + arr.back();
        for(int i = 1; i<(int)arr.size()/2; i++) ans = max(ans, arr[i] + arr[arr.size()-1-i]);
        return ans;
    }
};