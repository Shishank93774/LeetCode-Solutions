class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans(n);
        int f = pref[0];
        ans[0] = f;
        for(int i = 1; i<n; i++){
            ans[i] = pref[i-1]^pref[i];
        }
        return ans;
    }
};