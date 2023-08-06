class Solution {
public:
    int maximalSquare(vector<vector<char>> &arr) {
        
        int n = arr.size(), m = arr[0].size();
        /*
        int pre[n+1][m+1];
        
        for(int i = 0; i<=n; i++) pre[i][0] = 0;
        for(int j = 0; j<=m; j++) pre[0][j] = 0;
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                pre[i][j] = (arr[i-1][j-1] == '1') + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
            }
        }    
        
        auto chk = [&](int x)->bool{
            for(int i = 0; i+x<=n; i++){
                for(int j = 0; j+x<=m; j++){
                    int ii = i+x, jj = j+x;
                    if(pre[ii][jj] - pre[ii][j] - pre[i][jj] + pre[i][j] == x*x){
                        return true;
                    }
                }
            }
            return false;
        };
        
        int l = 1, r = min(n, m);
        
        while(l<=r){
            int mid = l + (r - l)/2;
            if(chk(mid)){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        
        return (l-1)*(l-1);
        */
        vector<vector<int> > dp(n, vector<int>(m, -1));
        auto rec = [&](int r, int c, auto &&rec)->int{
            if(r == n-1 and c == m-1) return (arr[r][c] == '1');
            if(r == n or c == m or arr[r][c] == '0') return 0;
            
            if(dp[r][c] != -1) return dp[r][c];
            int ans = 1 + min({rec(r+1, c, rec), rec(r, c+1, rec), rec(r+1, c+1, rec)});
            
            return dp[r][c] = ans;
        };
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int curMx = rec(i, j, rec);
                ans = max(ans, curMx*curMx);
            }
        }
        return ans;
    }
};