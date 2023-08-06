const int mod = 1e9+7;
class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        
        vector<vector<int> > dp(goal+1, vector<int>(n+1, -1));
        // ways to make i len playlist from first j songs (use all once)
        auto rec = [&](int i, int j, auto &&rec)->long long{ 
            if(i == 0 and j == 0) return 1;
            if(i == 0 or j == 0) return 0;
            
            if(dp[i][j] != -1) return dp[i][j];
            
            long long ans = rec(i-1, j-1, rec); // add new unique song
            ans = (1ll*ans * (n - j + 1))%mod; // we have (n - j + 1) choices
            
            ans = (ans + 1ll*rec(i-1, j, rec)*max(0, (j - k)))%mod; // use same song again from 1st j ones.
            return dp[i][j] = ans;
        };
        return rec(goal, n, rec);
    }
};