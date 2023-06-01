int dxy[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]) return -1;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int> > dist(n, vector<int>(m, INT_MAX));
        queue<array<int, 2> > qu;
        qu.push({0, 0});
        int d = 0;
        while(!qu.empty()){
            int sz = qu.size();
            while(sz--){
                auto f = qu.front(); qu.pop();
                int x = f[0], y = f[1];
                if(dist[x][y] != INT_MAX) continue;
                dist[x][y] = d;
                if(x == n-1 and y == m-1) return d+1;
                for(int i = 0; i<8; i++){
                    int tx = x + dxy[i][0], ty = y + dxy[i][1];
                    if(tx<0 or ty<0 or tx>=n or ty>=m or grid[tx][ty] or dist[tx][ty] != INT_MAX) continue;
                    qu.push({tx, ty});
                }
            }
            d++;
        }
        return -1;
    }
};