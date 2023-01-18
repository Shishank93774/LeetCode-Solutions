class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int a1 = INT_MIN;
        int n = arr.size();
        int sum = 0, totSum = 0;
        bool allNeg = true, allPos = true;
        int mx = INT_MIN;
        for(int i = 0; i<n; i++){
            mx = max(mx, arr[i]);
            sum += arr[i];
            if(arr[i] <= 0) allPos = false;
            else allNeg = false;
            totSum += arr[i];
            a1 = max(a1, sum);
            if(sum < 0) sum = 0;
        }
        if(allPos) return totSum;
        if(allNeg) return mx;
        int mn = INT_MAX;
        for(int i = 0; i<n; i++){
            sum += arr[i];
            mn = min(mn, sum);
            if(sum > 0) sum = 0;
        }
        return max(a1, totSum - mn);
    }
};