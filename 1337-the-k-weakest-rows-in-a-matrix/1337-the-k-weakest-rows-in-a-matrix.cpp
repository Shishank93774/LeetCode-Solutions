class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size(), i, j, sum;
        vector<int> cnt(n, 0), ans(n);
        for(i = 0; i<n; i++){
            sum = 0;
            for(j = 0; j<m; j++){
                sum += (mat[i][j]);
            }
            cnt[i] = sum;
            ans[i] = i;
        }
        
        sort(ans.begin(), ans.end(), [&](int a, int b){
            return (cnt[a] == cnt[b]?a<b:cnt[a]<cnt[b]);
        });
        int sz = n;
        while(sz > k){
            ans.pop_back();
            sz--;
        }
        return ans;
    }
};