long long dp[100005][2];
class Solution {
public:
    long long maxAlternatingSum(vector<int>& arr) {
        int n = arr.size();
        memset(dp, -1, sizeof dp);
        auto rec = [&](int i, bool plus, auto &&rec)-> long long{
            if(i == n) return 0;
            
            long long &ans = dp[i][plus];
            if(ans != -1) return ans;
            ans = rec(i+1, plus, rec);
            
            if(plus) ans = max(ans, arr[i] + rec(i+1, 0, rec));
            else ans = max(ans, -arr[i] + rec(i+1, 1, rec));
            
            return ans;
        };
        
        return rec(0, 1, rec);
    }
};