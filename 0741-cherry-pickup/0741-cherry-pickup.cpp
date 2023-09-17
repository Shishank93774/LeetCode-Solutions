int dp[51][51][51];

class Solution {
public:
    int cherryPickup(vector<vector<int>>& arr) {
        
        int n = arr.size();
        memset(dp, -1, sizeof dp);
        
        
        auto rec = [&](int i1, int j1, int j2, auto &&rec)->int{
            int i2 = i1 + j1 - j2;
            if(i1>=n or j1>=n or arr[i1][j1] == -1) return -1e9;
            if(i2>=n or j2>=n or arr[i2][j2] == -1) return -1e9;
            
            if(i1 == n-1 and j1 == n-1) return arr[n-1][n-1];
            if(dp[i1][j1][j2] != -1) return dp[i1][j1][j2];
            int &ans = dp[i1][j1][j2] = arr[i1][j1];
            
            if(j1 != j2) ans += arr[i2][j2];
            ans += max({rec(i1, j1+1, j2+1, rec), rec(i1+1, j1, j2+1, rec), rec(i1, j1+1, j2, rec), rec(i1+1, j1, j2, rec)});
            
            return ans;
        };
        
        return max(rec(0, 0, 0, rec), 0);
        
    }
};