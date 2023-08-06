class Solution {
public:
    int minimumTotal(vector<vector<int>> &arr) {
        
        int n = arr.size();
        vector<int> down(n+1, 0), cur(n+1);
        
        for(int r = n-1; r>=0; r--){
            for(int c = r; c>=0; c--){
                int ans = down[c];
                ans = min(ans, down[c+1]);
                ans += arr[r][c];
                cur[c] = ans;
            }
            down = cur;
            down.pop_back();
            cur.pop_back();
        }
        
        return down[0];
    }
};