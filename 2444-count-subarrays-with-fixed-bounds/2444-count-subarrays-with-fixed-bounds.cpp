class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = nums.size();
        vector<pair<int, int> > good;
        int pl = -1, pr = -1;
        for(int i = 0; i<n; i++){
            if(nums[i] < minK or nums[i] > maxK){
                if(pl != -1) good.push_back({pl, pr});
                pl = pr = -1;
            }else{
                if(pl == -1) pl = i;
                pr = i;
            }
        }
        if(pl != -1) good.push_back({pl, pr});
        if(minK == maxK){
            for(auto it: good){
                int d = it.second - it.first + 1;
                ans = ans + 1ll*d*(d+1)/2;
            }
            return ans;
        }
        for(auto it: good){
            int l = it.first, r = it.second;
            vector<int> mins, maxs;
            for(int i = l; i<=r; i++){ 
                if(nums[i] == minK) mins.push_back(i);
                else if(nums[i] == maxK) maxs.push_back(i);
            }
            int mnLen = mins.size(), mxLen = maxs.size();
            for(int i = l; i<r; i++){
                auto itmn = lower_bound(mins.begin(), mins.end(), i);
                auto itmx = lower_bound(maxs.begin(), maxs.end(), i);
                if(itmn == mins.end() or itmx == maxs.end()) break;
                int mn = *itmn, mx = *itmx;
                int rb = max(mn, mx);
                ans += (r - rb + 1);
            }
        }
        return ans;
    }
};