class Solution {
public:
    int diagonalSum(vector<vector<int>>& arr) {
        int ans = 0, n = arr.size();
        for(int i = 0; i<n; i++) ans += arr[i][i] + arr[i][n-1-i];
        if(n%2) ans -= arr[n/2][n/2];
        return ans;
    }
};