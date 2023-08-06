const int mod = 1e9+7;
int dp[5001][7][16];

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp, -1, sizeof dp);
        auto rec = [&](int i, int prv, int cnt, auto &&rec)->int{
            if(i == n) return 1;
            
            if(dp[i][prv+1][cnt] != -1) return dp[i][prv+1][cnt];
            int ans = 0;
            for(int die = 0; die<6; die++){
                if(die == prv and cnt==rollMax[die]) continue;
                ans += rec(i+1, die, (die==prv?cnt+1:1), rec);
                ans %= mod;
            }
            return dp[i][prv+1][cnt] = ans;
            
        };
        
        return rec(0, -1, 0, rec);
    }
};