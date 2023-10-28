const int mod = 1e9 + 7, N = 20001;
int dp[N][6];
vector<int> adj[6] = {{1, 2, 3, 4, 5}, {2}, {1, 3}, {1, 2, 4, 5}, {3, 5}, {1}};
bool done = false;
class Solution {
public:
    int countVowelPermutation(int n, int cur = 0) {
        if(n == 0) return 1;
        if(!done){
            memset(dp, -1, sizeof dp);
            done = true;
        }
        if(dp[n][cur] != -1) return dp[n][cur];
        int &ans = dp[n][cur] = 0;
        for(int nxt: adj[cur]){
            ans += countVowelPermutation(n-1, nxt);
            ans %= mod;
        }
        return ans;
    }
};