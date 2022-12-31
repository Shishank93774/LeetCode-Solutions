class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        vector<int> rnum1(n, 0);
        vector<int> cnum1(m, 0);
        for(int i = 0; i<n; i++){
            int x = 0;
            for(int j = 0; j<m; j++) x += arr[i][j];
            rnum1[i] = x;
        }
        for(int j = 0; j<m; j++){
            int x = 0;
            for(int i = 0; i<n; i++) x += arr[i][j];
            cnum1[j] = x;
        }
        vector<vector<int> > diff(n, vector<int>(m, 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                diff[i][j] = 2*rnum1[i] + 2*cnum1[j] - n - m;
            }
        }
        return diff;
    }
};