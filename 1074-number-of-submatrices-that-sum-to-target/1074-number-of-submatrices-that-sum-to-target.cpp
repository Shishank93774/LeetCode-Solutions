class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& arr, int tar) {
        int n = arr.size(), m = arr[0].size();
        
        vector<vector<int> > pre(n+1, vector<int>(m+1, 0));
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                pre[i][j] = arr[i-1][j-1] + pre[i][j-1] + pre[i-1][j] - pre[i-1][j-1];
            }
        }
        
        
        int ans = 0;
        for(int lx = 1; lx<=n; lx++){
            for(int ly = 1; ly<=m; ly++){
                for(int rx = lx; rx<=n; rx++){
                    for(int ry = ly; ry<=m; ry++){
                        int sum = pre[rx][ry] - pre[lx-1][ry] - pre[rx][ly-1] + pre[lx-1][ly-1];
                        ans += (sum == tar);
                    }
                }
            }
        }
        
        return ans;        
    }
};