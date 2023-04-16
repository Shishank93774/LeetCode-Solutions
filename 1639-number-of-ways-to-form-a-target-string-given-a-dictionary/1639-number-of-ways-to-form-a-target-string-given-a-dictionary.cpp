const int MOD = 1e9+7;
const int N = 1e3+3;
int dp[N][N];
class Solution {
    int rec(int i, int j, const string &target, int n, vector<unordered_map<char, int> > &kStr, int k){
        if(j == n) return 1;
        if(n-j > k-i) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int &ans = dp[i][j];
        ans = rec(i+1, j, target, n, kStr, k);
        unordered_map<char, int> &mp = kStr[i];
        if(mp.find(target[j]) != mp.end())
            ans = (ans + (1ll*rec(i+1, j+1, target, n, kStr, k)*mp[target[j]])%MOD)%MOD;
        return ans;
    }
public:
    int numWays(vector<string>& words, string target) {
        memset(dp, -1, sizeof dp);
        int n = words.size(), m = words[0].size();
        vector<unordered_map<char, int>> kStr(m);
        for(int j = 0; j<m; j++) for(int i = 0; i<n; i++) kStr[j][words[i][j]]++;
        return rec(0, 0, target, target.size(), kStr, m);
    }
};