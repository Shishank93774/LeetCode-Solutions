class Solution {
    void rec(int i, vector<int> &arr, int n, set<vector<int> > &st){
        if(i == n-1) st.insert(arr);
        for(int j = i;j<n; j++){
            swap(arr[i], arr[j]);
            rec(i+1, arr, n, st);
            swap(arr[i], arr[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& arr) {
        set<vector<int> > st;
        rec(0, arr, arr.size(), st);
        return vector<vector<int> >(st.begin(), st.end());
    }
};