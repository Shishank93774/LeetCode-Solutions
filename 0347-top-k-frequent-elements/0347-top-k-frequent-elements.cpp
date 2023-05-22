class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pqu;
        int i = 0, n = nums.size();
        while(i<n){
            int j = i, cnt = 0;
            while(j<n and nums[j] == nums[i]){j++; cnt++;}
            pqu.push({cnt, nums[i]});
            i = j;
            if(pqu.size() > k) pqu.pop();
        }
        vector<int> ans;
        while(!pqu.empty()){
            auto pr = pqu.top(); pqu.pop();
            ans.push_back({pr.second});
        }
        return ans;
    }
};