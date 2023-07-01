int dp[19][(1<<19)];
class Solution {
    int rec(int i, vector<int> &arr, int place, int n, int k){
        if(i == n) return 0;
        if(dp[i][place] != -1) return dp[i][place];
        int &ans = dp[i][place];
        for(int j = 0; j<k; j++){
            int lBit = 2*j+1, rBit = 2*j;
            if(place&(1<<lBit)) continue;
            if(place&(1<<rBit)){
                ans = max(ans, ((j+1)&arr[i]) + rec(i+1, arr, place|(1<<lBit), n, k));
            }else{
                ans = max(ans, ((j+1)&arr[i]) + rec(i+1, arr, place|(1<<rBit), n, k));
            }   
        }
        return ans;
    }
public:
    int maximumANDSum(vector<int>& arr, int k) {
        int n = arr.size();
        memset(dp, -1, sizeof dp);
        return rec(0, arr, 0, n, k);
    }
};