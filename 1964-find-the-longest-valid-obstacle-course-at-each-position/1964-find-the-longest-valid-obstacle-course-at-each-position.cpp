class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n), lis;
        dp[0] = 1;
        lis.push_back(arr[0]);
        for(int i = 1; i<n; i++){
            int x = arr[i];
            int idx = upper_bound(lis.begin(), lis.end(), x) - lis.begin();
            if(idx == lis.size()) lis.push_back(x);
            else lis[idx] = x;
            dp[i] = idx + 1;
        }
        return dp;
    }
};