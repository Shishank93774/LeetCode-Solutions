class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for(int x: nums){
            if(lis.size() and lis.back() >= x){
                auto it = lower_bound(lis.begin(), lis.end(), x);
                *it = x;
            }else{
                lis.push_back(x);
            }
        }
        return lis.size();
    }
};