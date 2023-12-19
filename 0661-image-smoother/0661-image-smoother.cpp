int dxy[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int> > ans(n, vector<int>(m));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int cnt = 1, sum = img[i][j];
                for(int k = 0; k<8; k++){
                    int ti = i+dxy[k][0], tj = j+dxy[k][1];
                    if(ti >= 0 and tj>=0 and ti<n and tj<m) sum += img[ti][tj], cnt++;
                }
                ans[i][j] = sum/cnt;
            }
        }
        return ans;
    }
};