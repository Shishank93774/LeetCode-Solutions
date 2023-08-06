int dx[2] = {0, 1};
int dy[2] = {1, 0};
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>> &arr) {
        int n = arr.size(), m = arr[0].size();
        
        vector<vector<int> > dp(n, vector<int>(m, 1));
        
        auto rec = [&](int r, int c, auto &&rec)->int{
            if(r == n-1 and c == m-1) return min(0, arr[r][c]);
            if(r == n or c == m) return -1e9;
            
            if(dp[r][c] != 1) return dp[r][c];
            
            int ans = rec(r+1, c, rec);
            ans = max(ans, rec(r, c+1, rec));
            
            ans += arr[r][c];
            
            ans = min(0, ans);
            
            return dp[r][c] = ans;
        };
        
        return abs(rec(0, 0, rec))+1;
    }
};