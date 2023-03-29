int dp[505][505];

class Solution {
    int rec(int i, int time, vector<int> &arr, int n){
        if(i == n) return 0;
        if(dp[i][time] != -1) return dp[i][time];
        return dp[i][time] = max(arr[i]*time + rec(i+1, time+1, arr, n), rec(i+1, time, arr, n));
    }
public:
    int maxSatisfaction(vector<int>& arr) {
        memset(dp, -1, sizeof dp);
        sort(arr.begin(), arr.end());
        return rec(0, 1, arr, arr.size());
        
        
        // int sum = 0, ans = 0;
        // sort(arr.begin(), arr.end(), greater<int>());
        // for(int i = 0; i<arr.size() and sum + arr[i] > 0; i++){
        //     sum += arr[i];
        //     ans += sum;
        // }
        // return ans;
        
    }
};