class Solution {
    int rec(int i, int remk, bool buyed, vector<int> &arr, int n, vector<vector<vector<int> > > &dp){
        if(i == n) return 0;
        if(remk == 0) return 0;
        
        if(dp[i][remk][buyed] != -1) return dp[i][remk][buyed];
        
        int a1 = rec(i+1, remk, buyed, arr, n, dp);
        int a2 = 0;
        if(buyed){
            a2 = arr[i] + rec(i+1, remk-1, false, arr, n, dp);
        }else{
            a2 = -arr[i] + rec(i+1, remk, true, arr, n, dp);
        }
        
        return dp[i][remk][buyed] = max(a1, a2);
    }
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<vector<int> > > dp(n, vector<vector<int> >(2+1, vector<int>(2, -1)));
        return rec(0, 2, false, arr, n, dp);
    }
};