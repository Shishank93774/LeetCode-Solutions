int dxy[5] = {0, 1, 0, -1, 0};

class Solution {
    int n, m, ans;
    
    void dfs(int x, int y, int left, vector<vector<int> > &arr){
        
        if(arr[x][y] == 2){
            ans += (left == 0);
            return;
        }
        arr[x][y] = -1;
        for(int i = 0; i<4; i++){
            int tx = x + dxy[i], ty = y + dxy[i+1];
            if(tx<0 or ty<0 or tx>=n or ty>=m or arr[tx][ty] == -1) continue;
            dfs(tx, ty, left-1, arr);
        }
        arr[x][y] = 0;
    }
    
    
public:
    int uniquePathsIII(vector<vector<int>>& arr) {
        n = arr.size(), m = arr[0].size();
        int tot = -1;
        int r = 0, c = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                tot += (arr[i][j] != -1);
                if(arr[i][j] == 1){
                    r = i, c = j;
                }
            }
        }
        ans = 0;
        dfs(r, c, tot, arr);
        return ans;
    }
};