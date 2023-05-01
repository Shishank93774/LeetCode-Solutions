class Solution {
public:
    double average(vector<int>& arr) {
        double ans = 0;
        int n = arr.size();
        long long sum = accumulate(arr.begin(), arr.end(), 0ll);
        sort(arr.begin(), arr.end());
        sum -= (arr[0] + arr[n-1]);
        ans = 1.0*sum/(n-2);
        return ans;
    }
};