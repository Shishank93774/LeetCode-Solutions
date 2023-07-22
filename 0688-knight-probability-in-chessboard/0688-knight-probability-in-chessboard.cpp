int moves[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
const int N = 26, K = 101;
const double mul = 1.0/8.0;

class Solution {
    double dp[N][N][K];
    double rec(int n, int k, int r, int c){
        if(r<0 or c<0 or r>=n or c>=n) return 0.0;
        if(k == 0) return 1.0;
        if(dp[r][c][k]) return dp[r][c][k];
        double ans = 0.0;
        for(auto [dx, dy]: moves){
            int x = dx + r, y = dy + c;
            ans += mul*rec(n, k-1, x, y);
        }
        return dp[r][c][k] = ans;
    }
public:
    double knightProbability(int n, int k, int r, int c) {
        return rec(n, k, r, c);
    }
};