class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){                
                int ti = 0;
                int tj = 0;
                while(tj<n and ti<n and grid[i][tj] == grid[ti][j])ti++, tj++;
                ans +=(ti == n and tj == n);
            }
        }
        return ans;
    }
};