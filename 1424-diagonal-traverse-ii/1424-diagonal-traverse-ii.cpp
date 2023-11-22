class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        
        queue<pair<int, int> > qu;
        qu.push({0, 0});
        while(!qu.empty()){
            auto [x, y] = qu.front(); qu.pop();
            ans.push_back(nums[x][y]);
            
            if(x+1<nums.size() and y==0) qu.push({x+1, y});
            
            if(y+1<nums[x].size()) qu.push({x, y+1});
        }
        
        return ans;
    }
};