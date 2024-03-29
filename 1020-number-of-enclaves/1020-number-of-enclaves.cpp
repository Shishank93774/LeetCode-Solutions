int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

class Solution {
    pair<bool, int> dfs(int r, int c, int n, int m, vector<vector<int> > &arr){
        if(r<0 or c<0 or r>=n or c>=m) return {false, 0};
        if(arr[r][c] == 0 or arr[r][c] == 2) return {true, 0};
        int cnt = 1;
        arr[r][c] = 2;
        bool chk = true;
        for(int i = 0; i<4; i++){
            int tx = r + dx[i], ty = c + dy[i];
            auto pr = dfs(tx, ty, n, m, arr);
            if(!pr.first) chk = false;
            cnt += pr.second;
        }
        if(chk) return {true, cnt};
        return {false, 0};
    }
    
public:
    int numEnclaves(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        int ans = 0;
        queue<pair<int, int> > qu;
        
        // for(int i = 0; i<n; i++)
        //     for(int j = 0; j<m; j++)
        //         if(arr[i][j] == 1){
        //             auto pr = dfs(i, j, n, m, arr);
        //             if(pr.first) ans += pr.second;
        //         }
        // return ans;
        auto dfs = [&](int r, int c, auto&& dfs) ->void{
            if(r<0 or c<0 or r>=n or c>=m or arr[r][c] == 0) return;
            arr[r][c] = 0;
            dfs(r+1, c, dfs), dfs(r-1, c, dfs), dfs(r, c+1, dfs), dfs(r, c-1, dfs);
        };
        for(int i = 0; i<n; i++){ 
            if(arr[i][0] == 1) dfs(i, 0, dfs);
            if(arr[i][m-1] == 1) dfs(i, m-1, dfs);
        }
        for(int j = 0; j<m; j++){ 
            if(arr[0][j] == 1) dfs(0, j, dfs);
            if(arr[n-1][j] == 1) dfs(n-1, j, dfs);
        }
        
        
        
        // while(qu.size()){
        //     pair<int, int> pr = qu.front(); qu.pop();
        //     int r = pr.first, c = pr.second;
        //     if(r<0 or c<0 or r>=n or c>=m or arr[r][c] == 0) continue;
        //     arr[r][c] = 0;
        //     qu.push({r, c+1}), qu.push({r, c-1}), qu.push({r-1, c}), qu.push({r+1, c});
        // }
        
        for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) ans += arr[i][j];
        return ans;
    }
};