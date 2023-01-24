class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), ans = 0;
        vector<bool> vis(n * n + 1, false);
        int s = 1, d = n*n;
        queue<int> qu;
        qu.push(s);
        while (qu.size()) {
            int sz = qu.size();
            while (sz--) {
                int f = qu.front(); qu.pop();
                if (f == d) return ans;
                if(vis[f]) continue;
                vis[f] = true;
                for (int nbr = f + 1; nbr <= min(d, f + 6); ++nbr) {
                    int x = (nbr - 1) / n, y = (nbr - 1) % n;
                    if (x % 2) y = n - 1 - y;
                    x = n - 1 - x;
                    int next = board[x][y] == -1 ? nbr : board[x][y];
                    qu.push(next);
                }
            }
            ans++;
        }
        return -1;
    }
};