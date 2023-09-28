class Solution {
public:
    vector<vector<int>> permute(vector<int>& arr) { 
        vector<vector<int> > ans;
        int n = arr.size();
        auto rec = [&](int i, auto &&rec)->void{
            if(i == n){
                ans.push_back(arr);
                return;
            }
            rec(i+1, rec);
            for(int j = i+1; j<n; j++){
                swap(arr[i], arr[j]);
                rec(i+1, rec);
                swap(arr[i], arr[j]);
            }
        };
        
        rec(0, rec);
        return ans;
    }
};