int dp[100005];
class Solution {
public:
    bool validPartition(vector<int> &arr) {
        int n = arr.size();
        memset(dp, -1, sizeof dp);
        auto rec = [&](int i, auto &&rec)->bool{
            if(i == n) return true;
            if(dp[i] != -1) return dp[i];
            int ans = 0;
            if(i+1<n and arr[i] == arr[i+1]){
                ans = rec(i+2, rec);
            }
            if(ans) return dp[i] = true;
            if(i+2<n and arr[i] == arr[i+1] and arr[i+1] == arr[i+2]){
                ans = rec(i+3, rec);
            }
            if(ans) return dp[i] = true;
            if(i+2<n and arr[i] + 1 == arr[i+1] and arr[i+1] + 1 == arr[i+2]){
                ans = rec(i+3, rec);
            }
            return dp[i] = ans;
        };
        
        return rec(0, rec);
        
    }
};