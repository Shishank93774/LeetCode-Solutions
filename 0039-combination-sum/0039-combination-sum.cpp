class Solution {
    void rec(int i, int target, vector<int> ans, set<vector<int> > &st, vector<int> &arr, int n){
        if(target < 0) return;
        if(i == n){
            if(target == 0) st.insert(ans);
            return;
        }
        rec(i+1, target, ans, st, arr, n);
        if(arr[i] <= target){
            ans.push_back(arr[i]);
            rec(i, target-arr[i], ans, st, arr, n);
            ans.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int> > res;
        rec(0, target, {}, res, candidates, candidates.size());
        return vector<vector<int>>(res.begin(), res.end());
    }
};