const int MAX = 2001;
int n, i, j;
class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        n = arr.size();
        for(i = 0; i<n; i++) for(j = 0; j<n; j++) if(j > i) swap(arr[i][j], arr[j][i]);
        for(j = 0; j<n/2; j++) for(i = 0; i<n; i++) swap(arr[i][j], arr[i][n-1-j]);
    }
};