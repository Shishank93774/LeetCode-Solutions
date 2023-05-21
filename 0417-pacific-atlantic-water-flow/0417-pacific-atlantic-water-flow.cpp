class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        vector<vector<int> > vis(n, vector<int>(m, false));
        
        auto dfs1 = [&](int r, int c, int cur, auto &&dfs1)->void{
            if(r<0 or c<0 or r>=n or c>=m or vis[r][c] or arr[r][c] < cur) return;
            vis[r][c] += 1;
            dfs1(r+1, c, arr[r][c], dfs1);
            dfs1(r-1, c, arr[r][c], dfs1);
            dfs1(r, c+1, arr[r][c], dfs1);
            dfs1(r, c-1, arr[r][c], dfs1);
        };
        
        auto dfs2 = [&](int r, int c, int cur, auto &&dfs2)->void{
            if(r<0 or c<0 or r>=n or c>=m or (vis[r][c] > 1) or arr[r][c] < cur) return;
            vis[r][c] += 2;
            dfs2(r+1, c, arr[r][c], dfs2);
            dfs2(r-1, c, arr[r][c], dfs2);
            dfs2(r, c+1, arr[r][c], dfs2);
            dfs2(r, c-1, arr[r][c], dfs2);
        };
        
        for(int j = 0; j<m; j++) dfs1(0, j, 0, dfs1);
        for(int i = 1; i<n; i++) dfs1(i, 0, 0, dfs1);
        
        for(int j = 0; j<m; j++) dfs2(n-1, j, 0, dfs2);
        for(int i = 0; i+1<n; i++) dfs2(i, m-1, 0, dfs2);
        
        vector<vector<int> > ans;
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++)
                if(vis[i][j] > 2) ans.push_back({i, j});
        
        return ans;
    }
};