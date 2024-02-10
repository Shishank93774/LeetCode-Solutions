auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();

vector<vector<bool> > vis, dp;
class Solution {
    bool rec(int l, int r, const string &str){
        if(l >= r) return dp[l][r] = true;
        
        if(vis[l][r]) return dp[l][r];
        vis[l][r] = true;
        if(str[l] == str[r]){
            return dp[l][r] = rec(l+1, r-1, str);
        }
        return dp[l][r] = false;
    }
public:
    int countSubstrings(const string &str) {
        int n = str.size(), ans = 0;
        vis.assign(n, vector<bool>(n, false));
        dp.assign(n, vector<bool>(n, false));
        
        for(int i = 0; i<n; i++)
            for(int j = i; j<n; j++)
                if(rec(i, j, str))
                    ans++;
        
        return ans;
    }
};