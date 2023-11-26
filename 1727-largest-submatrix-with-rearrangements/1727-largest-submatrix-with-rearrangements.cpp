class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        vector<int> prev(m, 0);
        int ans = 0;
        for(int i = 0; i<n; i++){
            vector<int> curr = mat[i];
            for(int j = 0; j<m; j++){
                if(curr[j]) curr[j] += prev[j];
            }
            vector<int> srt(curr);
            sort(srt.begin(), srt.end());
            for(int j = 0; j<m; j++) ans = max(ans, srt[j]*(m-j));
            prev = curr;
        }
        
        return ans;
    }
};