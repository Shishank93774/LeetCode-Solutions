int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<pair<int, int> > srcs;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1) srcs.push_back({i, j});
            }
        }
        vector<vector<int> > dists(n, vector<int>(m, -1));
        queue<pair<int, int> > qu;
        for(int i = 0; i<srcs.size(); i++){
            qu.push(srcs[i]);
        }
        int mx = -1;
        int d = 0;
        while(qu.size()){
            int sz = qu.size();
            while(sz--){
                auto pr = qu.front(); qu.pop();
                int x = pr.first, y = pr.second;
                if(dists[x][y] != -1) continue;
                if(grid[x][y] == 0){
                    mx = max(mx, d);
                }
                dists[x][y] = d;
                for(int i = 0; i<4; i++){
                    int tx = x + dx[i], ty = y + dy[i];
                    if(tx<0 or tx>=n or ty<0 or ty>=m or grid[tx][ty] == 1) continue;
                    qu.push({tx, ty});
                }
            }
            d++;
        }
        return mx;
    }
};