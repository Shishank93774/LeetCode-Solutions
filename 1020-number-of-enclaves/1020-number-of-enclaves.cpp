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
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++)
                if(arr[i][j] == 1){
                    auto pr = dfs(i, j, n, m, arr);
                    if(pr.first) ans += pr.second;
                }
        return ans;
    }
};