class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n+1, 0);
        int mxcnt = 0;
        for(int i = 0; i<n; i++) cnt[nums[i]]++, mxcnt = max(mxcnt, cnt[nums[i]]);
        vector<vector<int> > ans(mxcnt);
        for(int i = 1; i<=n; i++){
            for(int j = 0; j<cnt[i]; j++){
                ans[j].emplace_back(i);
            }
        }
        return ans;
    }
};