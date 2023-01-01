const int MAX = 2001;
int n, i, j;
class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        n = arr.size();
        for(i = 0; i<n; i++)
            for(j = 0; j<n; j++)
                arr[i][j] += 1000;
        
        for(i = 0; i<n; i++)
            for(j = 0; j<n; j++)
                arr[i][j] += ((arr[n-1-j][i])%MAX)*MAX;
        
        for(i = 0; i<n; i++)
            for(j = 0; j<n; j++){
                arr[i][j] /= MAX;
                arr[i][j] -= 1000;
            }
    }
};