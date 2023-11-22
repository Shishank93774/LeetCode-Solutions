class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        
        queue<pair<int, int> > qu;
        
        vector<vector<bool> > vis((int)nums.size());
        for(int i = 0; i<nums.size(); i++) vis[i].assign((int)nums[i].size(), false);
        
        qu.push({0, 0});
        while(!qu.empty()){
            auto [x, y] = qu.front(); qu.pop();
            ans.push_back(nums[x][y]);
            
            if(x+1<nums.size() and y<nums[x+1].size() and !vis[x+1][y]){
                vis[x+1][y] = true;
                qu.push({x+1, y});
            }
            
            if(y+1<nums[x].size() and !vis[x][y+1]){
                vis[x][y+1] = true;
                qu.push({x, y+1});
            }
            
        }
        
        return ans;
    }
};