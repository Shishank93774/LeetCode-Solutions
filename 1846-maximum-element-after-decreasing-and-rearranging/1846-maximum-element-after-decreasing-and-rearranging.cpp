class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int cur = 1;
        for(int i = 0; i<arr.size(); i++) cur += (arr[i] >= cur);
        return cur-1;
    }
};