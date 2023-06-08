class Solution {
    int bs(vector<int> arr, int l, int r){
        int idx = -1;
        while(l<=r){
            int mid = l + (r - l)/2;
            if(arr[mid] >= 0){
                l = mid + 1;
            }else{
                r = mid - 1;
                idx = mid;
            }
        }
        return idx;
    }
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();
        // for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) ans += (grid[i][j] < 0);
        // return ans;
        
        // for(int i = 0; i<n; i++){
        //     int idx = bs(grid[i], 0, m-1);
        //     if(idx != -1) ans += (m-idx);
        // }
        // return ans;
        
        int prvNeg = m-1;
        for(int i = 0; i<n; i++){
            int idx = bs(grid[i], 0, prvNeg);
            if(idx != -1){
                ans += (n-i)*(prvNeg - idx + 1);
                prvNeg = idx-1;
            }
        }
        return ans;
    }
};