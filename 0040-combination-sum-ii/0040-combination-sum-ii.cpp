class Solution {
    void rec(int i, int target, vector<int> till, vector<vector<int> > &ans, vector<int> &arr, int n){
        if(target == 0){
            ans.push_back(till);
            return;
        }
        
        for(int idx = i; idx<n; idx++){
            if(arr[idx] > target) return;
            if(i < idx and arr[idx-1] == arr[idx]) continue;
            till.push_back(arr[idx]);
            rec(idx+1, target-till.back(), till, ans, arr, n);
            till.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        rec(0, target, {}, ans, arr, arr.size());
        return ans;
    }
};