class Solution {
    int rec(int i, bool buyed, vector<int> &arr, int n, vector<vector<int> > &dp){
        if(i >= n) return 0;
        
        if(dp[i][buyed] != -1) return dp[i][buyed];
        
        int a1 = rec(i+1, buyed, arr, n, dp);
        int a2 = 0;
        if(buyed){
            a2 = arr[i] + rec(i+2, false, arr, n, dp);
        }else{
            a2 = -arr[i] + rec(i+1, true, arr, n, dp);
        }
        
        return dp[i][buyed] = max(a1, a2);
    }
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int> > dp(n, vector<int>(2, -1));
        return rec(0, false, arr, n, dp);
    }
};