class Solution {
    void rec(int i, int n, vector<int> &nums, vector<int> cur, set<vector<int> > &ans){
        if(i == n){
            if(cur.size() > 1){
                ans.insert(cur);
            }
            return;
        }
        rec(i+1, n, nums, cur, ans);
        if(cur.size() == 0){
            cur.push_back(nums[i]);
            rec(i+1, n, nums, cur, ans);
            cur.pop_back();
        }else{
            if(nums[i] >= cur.back()){
               cur.push_back(nums[i]);
               rec(i+1, n, nums, cur, ans);
               cur.pop_back(); 
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int> > a1;
        rec(0, nums.size(), nums, {}, a1);
        vector<vector<int> > ans;
        for(auto v: a1){
            ans.push_back(v);
        }
        return ans;
    }
};