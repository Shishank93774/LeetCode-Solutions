class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int> > ans;
        
        auto rec = [&](int i, vector<int> till, auto &&rec)->void{
            if(till.size() == k){
                ans.push_back(till);
                return;
            }
            if(i == n) return;
            for(int j = i+1; i<n; i++){
                till.push_back(i+1);
                rec(i+1, till, rec);
                till.pop_back();
            }
        };
        
        rec(0, {}, rec);
        return ans;
    }
};