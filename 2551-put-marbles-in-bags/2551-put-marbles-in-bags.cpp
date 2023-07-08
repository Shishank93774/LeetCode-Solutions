class Solution {
public:
    long long putMarbles(vector<int>& arr, int k) {
        int n = arr.size();
        if(n <= 2) return 0;
        vector<int> give(n-1);
        for(int i = 1; i<n; i++) give[i-1] = arr[i-1] + arr[i];
        sort(give.begin(), give.end());
        long long mn = accumulate(give.begin(), give.begin() + k - 1, 0ll);
        reverse(give.begin(), give.end());
        long long mx = accumulate(give.begin(), give.begin() + k - 1, 0ll);
        return (mx - mn);
    }
};