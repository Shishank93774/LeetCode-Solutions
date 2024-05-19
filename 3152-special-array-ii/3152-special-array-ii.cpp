class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(), q = queries.size();
        vector<bool> ans(q);
        vector<int> a(n-1);
        for(int i = 1; i<n; i++){
            a[i-1] = ((arr[i]%2) != (arr[i-1]%2));
        }
        vector<int> pref(n);
        pref[0] = 0;
        for(int i = 1; i<n; i++){
            pref[i] = pref[i-1] + a[i-1];
        }
        for(int i = 0; i<q; i++){
            int x = queries[i][0], y = queries[i][1];
            
            int v = pref[y] - pref[x];
            ans[i] = (v == (y-x));
        }
        return ans;
    }
};