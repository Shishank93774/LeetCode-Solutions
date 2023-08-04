const int arr[4][3] = {{1,1,1},{1,1,1},{1,1,1},{0,1,0}};
const int dir[8][2] = {{-2,-1},{-2,1},{-1,2},{1,2},{2,-1},{2,1},{-1,-2},{1,-2}};
const int mod = 1e9+7;
int dp[4][3][5001];
class Solution {
public:
    int knightDialer(int mv) {
        memset(dp, -1, sizeof dp);
        int n = 4, m = 3;
        auto rec = [&](int x, int y, int rem, auto &&rec){
            if(x<0 or y<0 or x>=n or y>=m or rem<0 or arr[x][y] == 0) return 0;
            if(rem == 0) return 1;
            
            if(dp[x][y][rem] != -1) return dp[x][y][rem];
            int ans = 0;
            for(int i = 0; i<8; i++){
                ans = (ans + rec(x+dir[i][0], y+dir[i][1], rem-1, rec))%mod;
            }
            
            return dp[x][y][rem] = ans;
        };
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(arr[i][j]) ans = (ans + rec(i, j, mv-1, rec))%mod;
            }
        }
        
        return ans;
    }
};