int dp[505][505];

class Solution {
    // int rec(int i, int time, vector<int> &arr, int n){
    //     if(i == n) return 0;
    //     if(dp[i][time] != -1) return dp[i][time];
    //     return dp[i][time] = max(arr[i]*time + rec(i+1, time+1, arr, n), rec(i+1, time, arr, n));
    // }
public:
    int maxSatisfaction(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        memset(dp, 0, sizeof dp);
        for(int i = arr.size() - 1; i>=0; i--){
            for(int time = 1; time<=arr.size(); time++) dp[i][time] = max(arr[i] * time + dp[i+1][time+1], dp[i+1][time]);
        }
        return dp[0][1];
            
        // memset(dp, -1, sizeof dp);
        // return rec(0, 1, arr, arr.size());
        
        
        // int sum = 0, ans = 0;
        // sort(arr.begin(), arr.end(), greater<int>());
        // for(int i = 0; i<arr.size() and sum + arr[i] > 0; i++){
        //     sum += arr[i];
        //     ans += sum;
        // }
        // return ans;
        
    }
};