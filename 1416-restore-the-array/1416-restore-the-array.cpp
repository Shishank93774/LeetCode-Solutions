const int N = 1e5+5;
int dp[N];
class Solution {
public:
    int numberOfArrays(string str, int k) {
        int n = str.size(), mod = 1e9+7;
        memset(dp, -1, sizeof dp);
        auto rec = [&](int i, auto &&rec) -> int{
            if(i == n) return 1;
            if(str[i] == '0') return 0;
            if(dp[i] != -1) return dp[i];
            int &ans = dp[i] = 0;
            long long cur = 0;
            for(int j = i; j<n; j++){
                cur = cur*10 + (str[j] - '0');
                if(cur > k) break;
                ans = (1ll*ans + rec(j+1, rec))%mod;
            }
            return ans;
        };
        return rec(0, rec);
    }
};