class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int ans = 0, n = mat.size(), m = mat[0].size();
        vector<int> colLeft(m, n);
        vector<int> rowLeft(n, m);
        unordered_map<int, pair<int, int> > mp;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                mp[mat[i][j]] = {i, j};
            }
        }
        for(int i = 0; i<arr.size(); i++){
            pair<int, int> pr = mp[arr[i]];
            int row = pr.first, col = pr.second;
            colLeft[col]--;
            rowLeft[row]--;
            if(colLeft[col] == 0 or rowLeft[row] == 0) return i;
        }
        return -1;
    }
};