class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> vals(n, 0), res;
        int ans = 0;
        for(int i = 0; i<queries.size(); i++){
            auto v = queries[i];
            int idx = v[0], val = v[1];
            if(idx-1>=0 and val == vals[idx-1]) ans++;
            if(idx+1<n and val == vals[idx+1]) ans++;
            if(idx-1>=0 and vals[idx] == vals[idx-1] and vals[idx] != 0) ans--;
            if(idx+1<n and vals[idx] == vals[idx+1] and vals[idx] != 0) ans--;
            vals[idx] = val;
            res.push_back(ans);
        }
        return res;
    }
};