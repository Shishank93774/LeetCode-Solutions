class Solution {
public:
    int maxProduct(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        return (arr[n-1]*arr[n-2]-arr[n-1]-arr[n-2]+1);
    }
};