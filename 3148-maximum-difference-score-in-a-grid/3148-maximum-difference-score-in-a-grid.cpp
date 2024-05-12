class Solution {
public:
    int maxScore(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        
        int pre[n][m];
        
        int ans = -1e9;
        
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                int bmax = -1e9;
                int rmax = -1e9;
                
                if(i+1<n){
                    bmax = max(pre[i+1][j], arr[i+1][j]);
                }
                if(j+1<m){
                    rmax = max(pre[i][j+1], arr[i][j+1]);
                }
                int mx = max(rmax, bmax);
                ans = max(ans, mx - arr[i][j]);
                pre[i][j] = max(rmax, bmax);
            }
        }
        
        return ans;
    }
};