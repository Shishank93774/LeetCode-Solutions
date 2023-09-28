class Solution {
    void rec(int i, vector<int> arr, int n, vector<vector<int> > &ans){
        if(i == n-1) {ans.push_back(arr); return;}
        // unordered_set<int> done;
        for(int j = i; j<n; j++){
            // if(done.count(arr[j])) continue;
            // done.insert(arr[j]);
            if(j>i and arr[i] == arr[j]) continue;
            swap(arr[i], arr[j]);
            rec(i+1, arr, n, ans);
            // swap(arr[i], arr[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& arr) {
        vector<vector<int> > ans;
        sort(arr.begin(), arr.end());
        rec(0, arr, arr.size(), ans);
        return ans;
    }
};