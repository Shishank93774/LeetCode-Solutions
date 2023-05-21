int dxy[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        vector<vector<int> > ans(n, vector<int>(m, -1));
        
        queue<array<int, 2> > qu;
        for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) if(arr[i][j] == 1) qu.push({i, j});   
        int cur = 0;
        while(!qu.empty()){
            int sz = qu.size();
            while(sz--){
                auto pr = qu.front(); qu.pop();
                int x = pr[0], y = pr[1];
                if(ans[x][y] != -1) continue;
                ans[x][y] = cur;
                for(int i = 0; i<4; i++){
                    int tx = x + dxy[i][0], ty = y + dxy[i][1];
                    if(tx<0 or ty<0 or tx>=n or ty>=m) continue;
                    qu.push({tx, ty});
                }
            }
            cur++;
        }
        return ans;
    }
};