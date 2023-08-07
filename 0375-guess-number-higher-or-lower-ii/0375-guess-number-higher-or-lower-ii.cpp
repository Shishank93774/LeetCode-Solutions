int dp[201][201];
bool chk = false;
class Solution {
public:
    int getMoneyAmount(int n) {
        if(!chk){
            memset(dp, -1, sizeof dp);            
            chk = true;
        }
        auto rec = [&](int l, int r, auto &&rec)->int{
            if(l > r) return 0;
            if(l == r) return 0;
            if(l+1 == r) return l;
            
            if(dp[l][r] != -1) return dp[l][r];
            
            int ans = 1e9;
            for(int x = l; x<=r; x++){
                ans = min(ans, x + max(rec(l, x-1, rec), rec(x+1, r, rec)));
            }
            
            return dp[l][r] = ans;
        };
        
        return rec(1, n, rec);
        
    }
};