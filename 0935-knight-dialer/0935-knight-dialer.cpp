vector<int> adj[10] = {{5, 7}, {6, 8}, {3, 7},
                       {2, 8, 9}, {}, {0, 6, 9},
                       {1, 5}, {0, 2}, {1, 3},
                               {3, 5}         };
const int mod = 1e9+7, N = 5001;
int dp[N][10];
bool chk = false;
class Solution {
    long long rec(int n, int pos){
        if(n == 0) return 1;
        if(dp[n][pos] != -1) return dp[n][pos];
        long long ans = 0ll;
        for(int next: adj[pos]){
            ans += rec(n-1, next);
            ans %= mod;
        }
        return dp[n][pos] = ans;
    }
public:
    int knightDialer(int n) {
        if(!chk){
            memset(dp, -1, sizeof dp);
            chk = true;
        }
        long long ans = 0;
        for(int i = 0; i<10; i++) {
            ans += rec(n-1, i);
            ans %= mod;
        }
        return ans;
    }
};