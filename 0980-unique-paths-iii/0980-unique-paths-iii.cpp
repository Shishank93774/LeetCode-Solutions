class Solution {
public:
    int cnt=0,c=0;
    void dfs(vector<vector<int>>& grid,int x,int y,int c){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]==-1)
            return;
        if(grid[x][y]==2){
            if(c==0)
                cnt++;
            return;
        }
        grid[x][y]=-1;
        dfs(grid,x+1,y,c-1), dfs(grid,x-1,y,c-1), dfs(grid,x,y+1,c-1), dfs(grid,x,y-1,c-1);
        grid[x][y]=0;

    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int x,y;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    x=i;
                    y=j;
                }else if(grid[i][j]==0){
                    c++;
                }
            }
        }
        dfs(grid,x,y,c+1);
        return cnt;
    };
};