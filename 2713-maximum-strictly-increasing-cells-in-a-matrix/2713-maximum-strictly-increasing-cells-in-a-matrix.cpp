class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        map<int, vector<int> > mp;
        for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) mp[arr[i][j]].push_back(i*m+j);
        
        int dp[n][m], dpr[n], dpc[m];

        memset(dp, 0, sizeof dp);
        memset(dpr, 0, sizeof dpr);
        memset(dpc, 0, sizeof dpc);

        for(auto &[x, vec]: mp){
            
            for(int pos: vec){
                int r = pos/m, c = pos%m;
                dp[r][c] = max(dpr[r], dpc[c]) + 1;
            }
            
            for(int pos: vec){
                int r = pos/m, c = pos%m;
                dpr[r] = max(dp[r][c], dpr[r]);
                dpc[c] = max(dp[r][c], dpc[c]);
            }
        }
        
        return max(*max_element(dpr, dpr + n), *max_element(dpc, dpc + m));
    }
};