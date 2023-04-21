int dp[101][101][101];
class Solution {
public:
    int profitableSchemes(int gsz, int minP, vector<int>& group, vector<int>& profit) {
        int n = profit.size(), mod = 1e9+7;
        auto rec = [&](int i, int curgsz, int remp, auto &&rec) -> int {
            if(curgsz < 0) return 0;
            if(i == n) return (remp <= 0);
            if(remp < 0) remp = 0;
            if(dp[i][curgsz][remp] != -1) return dp[i][curgsz][remp];
            int &ans = dp[i][curgsz][remp] = rec(i+1, curgsz, remp, rec);
            if(group[i] <= gsz){
                ans = (1ll*ans + rec(i+1, curgsz-group[i], remp - profit[i], rec))%mod;
            }
            return ans;
        };
        memset(dp, -1, sizeof dp);
        return rec(0, gsz, minP, rec);
    }
};