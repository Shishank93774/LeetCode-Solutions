class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        vector<long long> arr(n);
        for(int i = 0; i<n; i++) arr[i] = costs[i];
        sort(arr.begin(), arr.end());
        for(int i = 1; i<n; i++) arr[i] += arr[i-1];
        return upper_bound(arr.begin(), arr.end(), coins) - arr.begin();
    }
};